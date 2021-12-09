#ifndef FIRSTUNIQUE_H
#define FIRSTUNIQUE_H
#include <string>
#include <unordered_map>

using namespace std;

class SolutionFirstUniqChar {
public:
    int firstUniqChar(string s) {
        unordered_map <char, int> chHsh;
        for(size_t i = 0; i < s.size(); ++i){
            chHsh[s.at(i)] += 1;
        }
        for(size_t i = 0; i < s.size(); ++i){
            auto iter = chHsh.find(s.at(i));
            if (iter != chHsh.end())
                if(iter->second == 1)
                    return i;
        }


        return -1;

    }
};
#endif // FIRSTUNIQUE_H
