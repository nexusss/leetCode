// ConsoleApplication1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <type_traits>
#include <memory>

int foo() {
    int a = 66;
    return a;
}

int& foo1() {
    int a = 55;
    return a;
}

class Mystring {
    char* buf = nullptr;
    size_t size = 0;
    size_t capacity = 0;

public:
    explicit Mystring(){
    }

    Mystring(const Mystring& a) {
        capacity = a.capacity;
        size = a.size;

        for (size_t i = 0; i < size; ++i) {
            buf[i] = a.buf[i];
        }
    }

    Mystring& operator=(const Mystring& a) {
        if (this != &a) {
            delete buf;
            buf = new char[a.capacity];
            capacity = a.capacity;
            size = a.size;

            for (size_t i = 0; i < size; ++i) {
                buf[i] = a.buf[i];
            }
        }
        return *this;
    }

    virtual ~Mystring() {
        delete [] buf;
        std::cout << "mystring destructor" << std::endl;
    }


};


template <class T>
class MySharedPtr {
    T* data = nullptr;
    size_t *counter = nullptr;

    explicit MySharedPtr(T* data) :data(data),counter(new size_t)  {
        *counter++;
    }

    MySharedPtr(const MySharedPtr& ptr) {
        data = ptr.data;
        counter = ptr.counter;
        if (data != nullptr)
            *counter++;
    }

    MySharedPtr& operator=(const MySharedPtr& ptr) {
        if (this != &ptr) {
            data = ptr.data;
            counter = ptr.counter;
            if (data != nullptr)
                *counter++;
        }
    }

    T* operator->() { return data; }
    T& operator*() { return *data; }

    virtual ~MySharedPtr() {
        *counter--;
        if (*counter == 0)
            delete data;
    }
};

int main()
{

    Mystring* str = new Mystring();
    std::shared_ptr<Mystring> str_sp(str);


    int a = 2;
    auto a1 = a; //int a1
    auto a2 = &a; // int* a2
    auto& a3 = a; // int & a3
    auto&& a4 = a; // int & a4

    a = 3;

    std::cout << a1 << " " << a2 << " " << a3 << " " << a4 << std::endl;

    const int aa = 2;
    auto aa1 = aa; // int aa1
    auto aa2 = &aa; // const int* aa2
    auto& aa3 = aa; // const int &
    auto&& aa4 = aa; // const int &
    auto&& aa5 = &aa; // const int &

    aa1 = 3;

    std::cout << aa1 << " " << aa2 << " " << aa3 << " " << aa4 << std::endl;


    auto aaa1 = 5; //int aaa1
    //auto& aaa2 = 5; //not allowed
    auto&& aaa3 = 5; // int &&aaa3
    aaa3 = 6;
    std::cout << aaa1 << " " << aaa3 << std::endl;

    auto b = foo();
    //auto& b1 = foo();

    auto bb = foo1();
    auto& bb1 = foo1();


    std::cout << "Hello World!\n";
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
