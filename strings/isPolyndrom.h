#ifndef ISPOLYNDROM_H
#define ISPOLYNDROM_H
#include <string>
#include <ctype.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        for (int i = 0,k = s.size() - 1; i < k;){
            while (!(tolower(s.at(i)) - 'a' >= 0 && tolower(s.at(i)) - 'a' < 27) && i < k){
                ++i;
            }

            while (!(tolower(s.at(k)) - 'a' >= 0 && tolower(s.at(k)) - 'a' < 27) && i < k){
                ++k;
            }

            if(tolower(s.at(i)) != tolower(s.at(k)))
                return false;

            ++i;
            --k;
        }
        return true;
    }
};
#endif // ISPOLYNDROM_H
