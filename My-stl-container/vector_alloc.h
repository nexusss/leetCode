//
// Created by kd on 02/02/23.
//

#ifndef MY_STL_CONTAINER_VECTOR_ALLOC_H
#define MY_STL_CONTAINER_VECTOR_ALLOC_H


#include <cstdint>
#include <iostream>
#include <memory>


using std::cout;
using std::endl;

namespace mvector_alloc {
template<typename T, typename allocator = std::allocator<T>>

class Vector {
    size_t capacity;
    size_t size;
    T *array = nullptr;

    allocator alloc;
public:

    Vector() : capacity(2), size(0) {

        try {
            array = alloc.allocate(capacity);

        }
        catch (const std::bad_alloc&){
            cout << "bad alloc";
            capacity = 0;
        }
    }

    void reserve(size_t new_capacity) {
        cout << "reserve " << new_capacity << endl;

        //std::allocator<T> allocc;
        T *new_array = alloc.allocate(new_capacity);

/*
        try {
            auto new_array = new uint8_t[new_capacity * sizeof(T)];

        }
        catch (const std::bad_alloc&){
            cout << "bad alloc" << endl;
            return;
        }
  */
        size_t i = 0;
        try {
            for (; i < size; ++i) {

                T *new_value = (new_array + i);
                T *old_value = (array + i);
                alloc.construct(new_value, *old_value);
                //new (new_value) T(*old_value);

            }

            for (size_t new_i = 0; new_i < size; ++new_i) {
                T *old_value = (array + new_i);
                //old_value->~T();
                alloc.destroy(old_value);
            }

            //delete[] array;
            alloc.deallocate(array, capacity);

            array = new_array;

            this->capacity = new_capacity;
        }
        catch (...) {
            for (size_t new_i = 0; new_i < i; ++new_i) {
                T *new_value = (new_array + new_i);
                //new_value->~T();
                alloc.destroy(new_value);
            }
            //delete [] new_array;
            alloc.deallocate(new_array, new_capacity);
            throw;
        }


    }

    void resize() {

    }

    void push_back(T &&value) {
        if (capacity == 0){
            return;
        }

        try {
            if (size == capacity) {
                reserve(capacity * 2);
            }

            T *new_value = (array + size);
            //new (new_value) T(value);
            alloc.construct(new_value, value);
            ++size;
        }
        catch (...) {
            throw;
        }
    }

    T &operator[](size_t index) const {

        T *new_value = (array + index);
        return *new_value;
    }

    ~Vector() {
        for (size_t i = 0; i < size; ++i) {
            T *old_value = (array + i);
            //old_value->~T();
            alloc.destroy(old_value);
        }

        alloc.deallocate(array, capacity);

        //delete[] array;
    }
};
}

#endif //MY_STL_CONTAINER_VECTOR_ALLOC_H
