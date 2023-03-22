#include <iostream>
#include <vector>

using namespace std;
//самый простой случай, нужно для логирования
void* operator new(size_t n){
    cout << "allocated " << n << " bytes\n";
    return malloc(n);
}

void operator delete(void *ptr, size_t n){
    cout << "dealloc " << n << "bytes\n";
    free(ptr);
}

void* operator new[](size_t n){
    cout << "allocated[] " << n << " bytes\n";
    return malloc(n);
}

void operator delete[](void *ptr){
    cout << "dealloc[] "  << "bytes\n";
    free(ptr);
}

struct S{
    int x = 0;
    double d = 0.0;
    S(){
        throw 1;
    }
    static void* operator new(size_t n){
        cout << "struc alloc " << n << " bytes\n";
        return malloc(n);
    }

    static void operator delete(void *ptr, size_t n){
        cout << "struc dealloc " << n << "bytes\n";
        free(ptr);
    }
};

int main()
{
    int *p = new int[10];
    delete[] p;

    vector <string>v {"1"};
    cout << "Hello World!" << endl;
    try {
        S *s = new S();

        cout << "111\n";
        delete s;
    }  catch (...) {
        cout << "except\n";
    }

    return 0;
}
