//
// Created by kd on 31/01/23.
//

#ifndef MY_STL_CONTAINER_VECTOR_H
#define MY_STL_CONTAINER_VECTOR_H

#include <cstdint>
#include <iostream>
#include <memory>


using std::cout;
using std::endl;

namespace mvector {
template<typename T, typename allocator = std::allocator<T>>

class Vector {
    size_t capacity;
    size_t size;
    uint8_t *array;

    allocator alloc;
public:

    Vector() : capacity(2), size(0) {

        try {
            array = new uint8_t[capacity * sizeof(T)];
        }
        catch (const std::bad_alloc &) {
            cout << "bad alloc" << endl;
            capacity = 0;
            throw;
        }
    }

    void reserve(size_t new_capacity) {
        cout << "reserve " << new_capacity << endl;

        try {
            auto new_array = new uint8_t[new_capacity * sizeof(T)];
            size_t i = 0;
            try {
                for (; i < size; ++i) {

                    T *new_value = (T *) (new_array + i * sizeof(T));
                    T *old_value = (T *) (array + i * sizeof(T));

                    new(new_value) T(*old_value);

                }

                for (size_t new_i = 0; new_i < size; ++new_i) {
                    T *old_value = (T *) (array + new_i * sizeof(T));
                    old_value->~T();

                }

                delete[] array;

                array = new_array;

                this->capacity = new_capacity;
            }
            catch (...) {
                for (size_t new_i = 0; new_i < i; ++new_i) {
                    T *new_value = (T *) (new_array + new_i * sizeof(T));
                    new_value->~T();
                }
                delete[] new_array;
                throw;
            }

        }
        catch (const std::bad_alloc &) {
            cout << "bad alloc" << endl;
            return;
        }
    }

    void resize() {

    }

    void push_back(T &&value) {

        try {
            if (size == capacity) {
                reserve(capacity * 2);
            }

            T *new_value = (T *) (array + size * sizeof(T));
            new(new_value) T(value);
            ++size;
        }
        catch (...) {
            throw;
        }
    }

    T &operator[](size_t index) const {
        T *new_value = (T *) (array + index * sizeof(T));
        return *new_value;
    }

    ~Vector() {
        for (size_t i = 0; i < size; ++i) {
            T *old_value = (T *) (array + i * sizeof(T));
            old_value->~T();
        }

        delete[] array;
    }
};
}
#endif //MY_STL_CONTAINER_VECTOR_H
