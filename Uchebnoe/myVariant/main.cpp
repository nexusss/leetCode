#include <iostream>

using namespace std;

template<size_t N, typename T, typename ...Types>
struct getIndexByType{
    static const size_t value = N;
};

template<size_t N, typename T, typename Head, typename... Tail>
struct getIndexByType<N, T, Head, Tail...>{
    static const size_t value = std::is_same<T, Head>() ? N : getIndexByType<N + 1, T, Tail...>::value;
};

template<typename ... Types>
class variant{

private:
    template<typename ...TTypes>
    union VariadicUnion {};//специализация для пустого шаблоного параметра

    template<typename Head, typename ... Tail>
    union VariadicUnion<Head, Tail...> {
        Head head;
        VariadicUnion<Tail...> tail;

        template<size_t N, typename T>
        void put(const T& value){
            if constexpr (N == 0){
                new(&head) T(value);
            }
            else{
                tail.put<N-1>(value);
            }
        }
    };

    VariadicUnion<Types...> storage;

    size_t current = 0;


public:
    template<typename T>
    bool holdsAlternative(){
        return getIndexByType<0,T, Types...>::value == current;
    }

    size_t index(){
        return current;
    }


    template<typename T>
    variant(const T& value){
        current = getIndexByType<0,T,Types...>::value;
        storage.put<getIndexByType<0,T,Types...>::value > (value);
    }
};

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}
