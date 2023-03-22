#include <iostream>

using namespace std;

template <typename T>
class shared_ptr{

    T *ptr = nullptr;
    size_t *count = nullptr;

    template<typename  U>
    struct controlBlock{
        U object;
        size_t counter;
    };

    controlBlock<T> *cptr = nullptr;

    template<typename U, typename ...Args>
    friend shared_ptr<U> make_shared(Args&&... args);

    struct make_shared_t;

    template<typename... Args>
    shared_ptr(controlBlock<T> *storage):cptr(storage){

    }

public:

    shared_ptr(T *ptr): ptr(ptr){count = new size_t(1);}
    shared_ptr(const shared_ptr<T> &other): ptr(other.ptr), count(other.count){
        ++*count;
    }

    shared_ptr(shared_ptr<T>&& other):ptr(other.ptr), count(other.count){
        other.ptr = nullptr;
        other.count = nullptr;
    }

    T& operator*() const{
        return *ptr;
    }

    T* operator->() const{
        return ptr;
    }

    ~shared_ptr(){
        if(*count > 1){
            *count--;
        }
        else{
            delete ptr;
            delete count;
        }
    }
};

template <typename T, typename... Args>
shared_ptr<T> make_shared(Args&&... args){
    auto ptr = new controlBlock<T>{1, T{std::forward<Args>(args)...}};
    return shared_ptr<T>(make_shared_t(), ptr);
}

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}
