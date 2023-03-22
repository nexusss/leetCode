#pragma once


#include <cstdint>
#include <array>
#include <mutex>
#include <condition_variable>
#include <atomic>

namespace bigFileSort {


template<size_t N>
class RingIterator{
    decltype (N) max = N;
    decltype (N) pos = 0;
public:
    explicit RingIterator() noexcept = default;

    auto operator++(int) noexcept{
        auto temp = *this;
        if (pos + 1 < N){
            ++pos;
        }
        else{
            pos = 0;
        }
        return temp;
    }


    bool operator==(const RingIterator &a)const noexcept{
        return this->pos == a.pos;
    }

    operator decltype (N)() const{
        return pos;
    }
};

template <class T, size_t N = 256>
class RingBuffer{
    std::vector<T> value;
    RingIterator<N> readPos;
    RingIterator<N> writePos;
    size_t size = 0;
    std::atomic<bool> noMoreData = false;
    std::mutex mutex;
    std::condition_variable cv;
    std::condition_variable cvFull;

public:
    explicit RingBuffer() noexcept : value(N){}

    bool top(T &result) noexcept{

        std::unique_lock<std::mutex> lk(mutex);
        cv.wait(lk, [&]{return size > 0 or noMoreData;});

        if(noMoreData and size == 0){

            return false;
        }
        result = std::move(value[readPos++]);
        size--;
        cvFull.notify_one();
        return true;
    }

    bool isFull(){
        std::unique_lock<std::mutex> lk(mutex);
        return size == N;
    }

    bool isFullWait(){
        std::unique_lock<std::mutex> lk(mutex);
        cvFull.wait(lk, [&]{return size < N or noMoreData;});
        if(noMoreData){
            return true;
        }
        return false;
    }

    void setNoMoreData(){
        noMoreData = true;
        cv.notify_one();
    }

    bool getNoMoreData(){
        return noMoreData;
    }

    void pushBack(T &&value) noexcept{
        std::unique_lock<std::mutex> lk(mutex);
        this->value[writePos++] = std::move(value);
        size++;
        cv.notify_one();
    }
};
}
