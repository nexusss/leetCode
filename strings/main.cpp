#include <iostream>

using namespace std;

int reverse(int x) {
        if (x != 0){
            reverse(x >> 8 );
        }
        return (x & 0xff) << 8;
    }

int main()
{
    cout << "Hello World!" << reverse(51) << endl;
    return 0;
}
