#include <iostream>

using namespace std;

template <typename T>
class S{
public:
    S() = default;
    template<typename U>
    S(U u){cout << "constr\n";}
    S(const S<T>&s) { cout << "copy constr\n";}
};

int main()
{
    S<int> s;
    S<int> s2(s);
    cout << "Hello World!" << endl;
    return 0;
}
