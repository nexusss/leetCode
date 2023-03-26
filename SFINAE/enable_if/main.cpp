#include <iostream>
#include <string>

#include <type_traits>

//using namespace std;

template <bool B>
struct enable_if{

};

template<>
struct enable_if<true>{
    using type = void;
};

template <bool B>
    using enable_if_t = typename enable_if<B>::type;


template <typename T, typename = enable_if_t<std::is_class_v<T>>>
void f(const T& x){
    std::cout << 1;
}

void f(...){
    std::cout << 2;
}

int main(){
    std::string s("abc");
    f(s);
    f(1);
    return 0;
}
