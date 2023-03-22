#ifndef ISANAGRAM_H
#define ISANAGRAM_H
#include <string>

using namespace std;
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        if (p.size() > s.size())
            return res;
        
        array<int, 26> s1Arr = {0};
        array<int, 26> s2Arr = {0};
        
        
        
        for (auto &pc: p){
            s1Arr[pc - 'a']++;
        }
        
        for (size_t i = 0; i < p.size(); i++){
            s2Arr[s[i] - 'a']++;
        }
        
        if (s1Arr == s2Arr){
            res.push_back(0);
        }
        
        for (size_t start = 0, end = p.size(); end < s.size(); ++end, ++start){
            s2Arr[s[start] - 'a']--;
            s2Arr[s[end] - 'a']++;
            if (s1Arr == s2Arr){
                res.push_back(start + 1);
            }
        }
        
        return res;
        
    }
};
#endif // ISANAGRAM_H
