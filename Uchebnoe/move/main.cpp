#include <iostream>
#include <cstring>

using namespace std;

template <typename T>
class TestMove{
    T* data = nullptr;
    int size = 0;

public:

    TestMove(){

    }

    TestMove(int size): data(new T[size]), size(size){

    }


    TestMove(const TestMove<T>& t){
        cout << "Copy constr\n";
        auto tmp = t;
        swap(tmp);
    }

    TestMove<T>& operator=(const TestMove<T>& t){
        cout << "op=\n";
        if (this != &t){

            try{
                auto tmpdata = new T[t.size];
                for(int i = 0; i < t.size; ++i){
                    tmpdata[i] = t.data[i];
                }

                //if (data != nullptr){
                    delete[] data;
                //}
                data = tmpdata;
                size = t.size;
            }
            catch(...){
                throw;
            }

            size = t.size;
        }
        else{
            cout << "eq\n";

        }
        return *this;
    }

    TestMove(TestMove<T>&& t):data(t.data),size(t.size){
        cout << "Move constr\n";
        t.data = nullptr;
        t.size = 0;
        //*this = std::move(t);
    }

    TestMove<T>& operator=(TestMove<T>&& t){
        cout << "move(op=)\n";
        if (this != &t){
            delete[] data;
            data = t.data;
            size = t.size;
            t.data = nullptr;
            t.size = 0;
        }
        else{
            cout << "eq\n";
        }
        return *this;
    }

    T& operator[](size_t index){
        return data[index];
    }

    void print(){
        for(size_t i = 0; i < size; ++i){
            data[i].print();
        }
    }

    ~TestMove(){
        cout << "destr " << size << endl;

        delete[] data;
        size = 0;
    }

};

struct S{
    size_t sz = 0;
    char *str = nullptr;

    S() = default;

    S(char *str):sz(strlen(str)), str(new char[sz]){
        memcpy(this->str, str, sz);
    }

    S(const S &s){
        *this = s;
    }

    S& operator=(const S& s){
        if (this != &s and s.sz > 0){
            try {
                auto tmp = new char[s.sz];
                memcpy(tmp, s.str, s.sz);
                delete[] str;
                str = tmp;
                sz = s.sz;
            }  catch (
            ...) {
                throw;
            }
        }

        return *this;
    }

    ~S(){
        delete[] str;
        sz = 0;
    }

    void print(){
        for (size_t i = 0; i < sz; ++i){
            cout << str[i];
        }
        cout << endl;
    }
};

int main()
{
    //TestMove<int> t(5);
    //TestMove<int> tc(std::move(t));
    //TestMove<int> tc = t;


    TestMove<S> s(3);
    s[0] = S("012");
    s[1] = S("345");
    s[2] = S("678");

    TestMove<S> sc(s);


    TestMove<S> sm(std::move(s));
sm.print();
s.print();
    //tc = t;
    cout << "Hello World!" << endl;

    int &&a = 5;
    int &&b = std::move(a);

    cout << &b << endl;

    return 0;
}
