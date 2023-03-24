//
// Created by kd on 31/01/23.
//

#ifndef MY_STL_CONTAINER_UNORDERED_SET_H
#define MY_STL_CONTAINER_UNORDERED_SET_H

#include <iostream>

template <typename Key, typename Value>
class Unorderded_set{

    struct List{
        Key key;
        Value value;
        List *next;
        List(Key&& key, Value&& value): key(std::forward<Key>(key)), value(std::forward<Value>(value)), next(nullptr) {}
    };

    uint8_t *array;
    uint16_t *exist;
    size_t size;

    size_t get_hash(const Key &key) const{
        //cout <<  std::hash<Key>{}(key) % size << endl;
        return std::hash<Key>{}(key) % size;
    }

public:
    Unorderded_set():size(10), array(new uint8_t [size * sizeof(List)]), exist(new uint16_t [size]) {

        for(size_t i = 0; i < size; ++i){
            exist[i] = 0;
        }

    }


    void insert(Key &&key, Value&& value){
        const auto index = get_hash(key);
        if(exist[index] == 0) {
            new(array + index * sizeof(List)) List(std::forward<Key>(key), std::forward<Value>(value));
        }
        else{
            List *list = (List *) (array + index * sizeof(List));

            while(list->next != nullptr){
                list = list->next;
            }
            list->next = new List(std::forward<Key>(key), std::forward<Value>(value));
        }

        exist[index]++;
    }


    Value& operator[](Key &&key){
        const auto index = get_hash(key);
        if (exist[index] == 0) {
            new(array + index * sizeof(List)) List(std::forward<Key>(key), std::forward<Value>(Value()));
        }

        List *list = (List *) (array + index * sizeof(List));

        while(list->key != key){
            if (list->next != nullptr) {
                list = list->next;
            }
            else if(key != list->key){
                list->next = new List(std::forward<Key>(key), std::forward<Value>(Value(std::to_string(index))));
                break;
            }
        }

        return list->value;

    }

    ~Unorderded_set(){
        cout << "destr" << endl;
        for(size_t i = 0; i < size; ++i){
            if(exist[i]){
                List *list = (List *) (array + i * sizeof(List));
                list->value.~Value();
                list = list->next;
                while(list != nullptr){
                   auto next = list->next;
                   delete list;
                   list = next;
                }
            }
        }

        delete [] array;
        delete [] exist;
    }
};

#endif //MY_STL_CONTAINER_UNORDERED_SET_H
