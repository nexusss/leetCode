#include <iostream>
#include <vector>
#include <string>


template <typename  T>
class M_allocator: public std::allocator<T>{
public:
    T* allocate(size_t count) const {
        std::cout << "allocate " << count << std::endl;
        return ::operator new(count * sizeof (T));
    }

    void deallocate(T* ptr, size_t){
        std::cout << "deallocate " << std::endl;
        :: operator delete(ptr);
    }

    template<typename... Args>
    void construct(T *ptr, const Args&... args){
        std::cout << "allocate constr " << std::endl;
        new(ptr) T(args...);
    }

    void destroy(T* ptr){
        std::cout << "destroy " << std::endl;
        ptr->~T();
    }
};

template <typename T, typename Alloc = std::allocator<T>>

class Vector {
private:
    T *arr;
    size_t sz;
    size_t cap;
    Alloc alloc;
public:
    Vector(size_t count, const T& value, const Alloc& alloc = Alloc()):alloc(alloc){
        reserve(count);
        for(size_t i = 0; i < count; ++i){
            alloc.construct(arr + i, value);
        }
    }

    void resize(size_t n, const T& value = T()){
        if (n > cap) reserve(n);

        for(size_t i = sz; i < sz; ++i){
            //arr[i] == value;
            new (arr + i) T(value);
        }

        if (n < sz){
            sz = n;
        }
    }

    void reserve(size_t n){

        //из-за того, что у нас не может быть конструкторов по умолчанию
        // то создаем массив байт
        //потом через placement_new мы копируем старые объекты
        // копирование через placement_new нужно, потому что объект не сконстрирован
        // и у него нельзя вызвать оператор присваивания
        // удаление тоже меняется, потому что создаем по сути массив байт
        // и нам надо принудительно вызвать деструкторы сначала

        //2 проблема это безопасность исключений

        if (n <= cap) return;
        auto newarr = alloc.allocate(n);
        //T* newarr = new (arr) T[n];

        size_t i = 0;
        try{//а вот это все можно заменить
            //unitialized_copy(iter first, iter end, iter d_first)
            for(size_t i = 0; i < sz; ++i){
                new (newarr + i) T(arr[i]);
                //newarr[i] = arr[i];
            }
        }
        catch(...){//безопасность исключений
            for (size_t j = 0; j < i; ++j){
                (newarr + j)->~T();
            }

            //delete[] reinterpret_cast<int8_t*>(newarr);
            alloc.deallocate(newarr, n);
            throw;
        }

        /*this is better
         * try {
            std::uninitialized_copy(arr, arr+sz, newarr);
        }  catch (...) {
            delete[] reinterpret_cast<int8_t*>(newarr);
            throw;
        } */

        for(size_t i = 0; i < sz; ++i){
            //(arr + i)->~T();
            alloc.destroy(arr + i);
        }

        //delete[] reinterpret_cast<uint8_t*>(arr);
        alloc.deallocate(arr);
        //delete[] arr
        arr = newarr;
        cap = n;
    }

    void push_back(const T& value){
        //потому что мы создаем массив байт
        //у нас нет объекта, мы не можем вызывать оператор присваивания
        // и через placement_new вызываем констр
        if (cap == sz){
            reserve( 2 * sz);
        }
            //arr[sz] = value;
        (arr + sz)->T(value);
            ++sz;

    }

    void pop_back(){
        --sz;
    }
};

int main()
{
    int a, b;
    std::forward(a);
    using MyString = std::basic_string<char, std::char_traits<char>, M_allocator<char>>;
    std::vector<MyString, M_allocator<std::string>> v;
    v.push_back("abc");
    return 0;
}
