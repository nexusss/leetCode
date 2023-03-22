#include <iostream>
#include <type_traits>

using namespace std;

template< class T > struct m_remove_pointer                    {typedef T type;};
template< class T > struct m_remove_pointer<T*>                {typedef T type;};
template< class T > struct m_remove_pointer<T* const>          {typedef T type;};
template< class T > struct m_remove_pointer<T* volatile>       {typedef T type;};
template< class T > struct m_remove_pointer<T* const volatile> {typedef T type;};

template<typename _Tp>
  using m_remove_pointer_t = typename m_remove_pointer<_Tp>::type;

template<typename T>
bool m_is_pointer(){
    return std::is_same_v<m_remove_pointer_t<T>*, T>;
}

int main()
{
    int a = 0;
    int *b = new int;
     decltype (b) c = new int;

    cout << "is same\n";
    cout << is_same<int *, std::remove_pointer<decltype (b)>::type*>::value << std::endl;
    cout << m_is_pointer<decltype (a)>() << " " << m_is_pointer<decltype (b)>() << std::endl;
    cout << std::is_pointer<decltype (a)>::value << " " << std::is_pointer<decltype (b)>::value << std::endl;
    cout << typeid(a).name() << " " << typeid(b).name() << "end";
    delete b;
    delete c;
    return 0;
}
