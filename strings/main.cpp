#include <iostream>
#include <string>
#include <unordered_map>
#include <bits/stdc++.h>
#include <hash_fun.h>

using namespace std;

int strStr(string haystack, string needle) {
        if (haystack.empty() and needle.empty())
            return 0;
        else if (haystack.size() < needle.size())
            return -1;
        else if (!haystack.empty() and needle.empty())
            return 0;

         std::size_t h1 = std::hash<std::string>{}(needle);

        for(int i = 0; i < haystack.size() - needle.size() + 1; ++i){
            auto i2 = i + needle.size() - 1;
            auto substr = haystack.substr(i, needle.size() - 1);
            auto h2 = std::hash<std::string>{}(haystack.substr(i, needle.size()));
            if (h1 == std::hash<std::string>{}(haystack.substr(i, needle.size()))){
                return i;
            }
        }


        return -1;
    }

struct A{
       int val = 0;
};

int main()
{
    A *a = new A;
    uint64_t b = (uint64_t)a;
    cout << a << "=" << b;

    cout << "Hello World!" << strStr("mississippi","issip") << endl;
    return 0;
}
