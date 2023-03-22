#ifndef ISANAGRAM_H
#define ISANAGRAM_H
#include <string>

using namespace std;
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size())
            return false;
        
        array<int, 26> s1Arr = {0};
        array<int, 26> s2Arr = {0};
        
        for (auto &s: s1){
            s1Arr[s - 'a']++;
        }
        
        for (size_t i = 0; i < s1.size(); i++){
            s2Arr[s2[i] - 'a']++;
        }
        
        if (s1Arr == s2Arr){
            return true;
        }
        
        for (size_t start = 0, end = s1.size(); end < s2.size(); ++end, ++start){
            s2Arr[s2[start] - 'a']--;
            s2Arr[s2[end] - 'a']++;
            if (s1Arr == s2Arr){
                return true;
            }
        }
        
        return false;
        
    }
};
#endif // ISANAGRAM_H
