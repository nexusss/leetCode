//
// Created by kd on 02/02/23.
//

#ifndef MY_STL_CONTAINER_VAR_TEMP_H
#define MY_STL_CONTAINER_VAR_TEMP_H

#include <iostream>

using std::cout;
using std::endl;

namespace var_temp{

void func(){
    cout << "func no args" << endl;
}

void func(int a){
    cout << "func int " << a << endl;
}

void func(double a){
    cout << "func double " << a << endl;
}

void func(int a, double b){
    cout << "func int " << a << " double b " << b << endl;
}

template <class ...Args>
void tfunc(Args... args){
    func(args...);
}
}
#endif //MY_STL_CONTAINER_VAR_TEMP_H
