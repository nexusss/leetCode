#include <iostream>
#include <vector>

using namespace std;

template <typename T>

auto f(T& x) ->decltype(T().size()){

    return 1;
}

int f(...){
    return 2;
}

int main()
{
    vector<int> v{1,2,4};
    cout << f(v) << endl; // 1

    cout << f(1) << endl; // 2
    cout << "Hello World!" << endl;
    return 0;
}
