#pragma once

#include <cstdint>
#include <array>
#include <vector>
#include <mutex>
#include <atomic>
#include <condition_variable>


namespace bigFileSort {

using std::size_t;


template <size_t N>
class posArrayThreadSafe{
    std::vector<size_t> pos;

    mutable std::mutex mutex;
    std::condition_variable cv;
    std::atomic<bool> noMoreData;

public:
    explicit posArrayThreadSafe() noexcept {
        pos.reserve(N);
        noMoreData = false;
    }

    int64_t index() noexcept{
        std::unique_lock<std::mutex> lk(mutex);
        cv.wait(lk, [&]{return !pos.empty() or noMoreData;});
        if (pos.empty() and noMoreData){
            return -1;
        }
        const size_t index = pos.back();
        pos.pop_back();
        return index;
    }

    void pushBack(const size_t index) noexcept{
        std::unique_lock<std::mutex> lk(mutex);
        pos.push_back(index);
        cv.notify_all();
    }

    void setNoMoreData(){
        noMoreData = true;
        cv.notify_all();
    }

};

template <class T, size_t N = 3>
class ArrayThreadSafe{
    std::array<T, N> value;

    posArrayThreadSafe<N> sortPos;
    posArrayThreadSafe<N> writePos;

public:
    explicit ArrayThreadSafe() noexcept {
        for(size_t i = 0; i < N; ++i){
            writePos.pushBack(i);
        }
    }

    T &getValue(size_t index) noexcept{
        return value[index];
    }

    size_t sortIndex() noexcept{
        return sortPos.index();
    }

    void sortPushBack(const size_t index) noexcept{
        sortPos.pushBack(index);
    }

    size_t writeIndex() noexcept{
        return writePos.index();
    }

    void writePushBack(const size_t index) noexcept{
        writePos.pushBack(index);
    }

    void setNoMoreData(){
        sortPos.setNoMoreData();
    }

    size_t size(){
        return N;
    }
};
}
