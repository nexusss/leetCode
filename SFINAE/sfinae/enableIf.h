#ifndef ENABLEIF_H
#define ENABLEIF_H
#include <iostream>
#include <string>

#include <type_traits>

using namespace std;
template <typename T>
void f(const T& x){
    cout << 1;
}

void f(...){
    cout << 2;
}

int main(){
    string s("abc");
    f(s);
    f(1);
}



#endif // ENABLEIF_H
