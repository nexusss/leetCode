#include <iostream>
#include <vector>

using namespace std;

//integral const
//константна времени компиляции
template <typename T, T _value>
struct integral_constant{
    static const T value = _value;
};

//true type
//integral const bool true/false
//это специальный тип
struct true_type: public integral_constant<bool, true> {};

struct false_type: public integral_constant<bool, false>{};

template <typename T>

auto f(T& x) ->decltype(T().size()){

    return 1;
}

int f(...){
    return 2;
}

//decltype value -> type
//declval type -> value of iys type

//checker method in class
template <typename T, typename... Args>
struct has_method{
private:
    template <typename TT, typename ...AArgs>
    static auto f(int) ->decltype(declval<TT>().construct(declval<AArgs>()...), int()){
        return 1;
    }
    template <typename ...>
    static char  f(...){
        return 0;
    }

public:
    static const bool value = sizeof(f<T, Args...>(0)) == sizeof(int);
};

/*
template <typename T, typename... Args>
struct has_method{
private:
    template <typename TT, typename ...AArgs, typename = decltype(declval<TT>().construct(declval<AArgs>()...))>
    static true_type f(int)
    template <typename ...>
    static false_type f(...)

public:
using type = decltype(f<T, Args...>(0);
    //static const bool value = sizeof(f<T, Args...>(0)) == sizeof(int);
};
template <typename T, typename... Args>
bool has_method_v = is_same_v<typename has_method<T, Args...>::value;

*/

template <typename T, typename... Args>
bool has_method_v = has_method<T, Args...>::value;

//enable if


struct Test{
    Test(int);
    void construct(int, int);
    void construct(double);
    void construct(const string&);
};

int main()
{
    vector<int> v{1,2,4};
    cout << f(v) << endl; // 1

    cout << f(1) << endl; // 2
    cout << has_method_v<Test, int, int> << endl;
    cout << has_method_v<Test, int, int, int> << endl;
    cout << "Hello World!" << endl;
    return 0;
}
