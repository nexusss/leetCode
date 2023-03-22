#include <iostream>
#include <vector>



template <typename T>

class Vector {
private:
    T *arr;
    size_t sz;
    size_t cap;

public:
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
        auto newarr = reinterpret_cast<T*>(new uint8_t[n * sizeof (T)]);
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

            delete[] reinterpret_cast<int8_t*>(newarr);
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
            (arr + i)->~T();
        }

        delete[] reinterpret_cast<uint8_t*>(arr);
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


    return 0;
}
