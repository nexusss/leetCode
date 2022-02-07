#ifndef SINGLENUMBER_H
#define SINGLENUMBER_H
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        //int64_t sum = 0;
        int arr[26] = {0};
        int n = s.length(), m = t.length();
        if(n != m)
            return false;
        
        for(int i=0;i < n;i++) {
            //sum += (s[i]-'a');
            //sum -= (t[i]-'a');
            arr[s[i]-'a']++;
            arr[t[i]-'a']--;
        }
        for(int i=0;i<26;i++){
            if(arr[i]!=0)return false;
        }
        return true;
    }
    
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string> > result;
        map<string, vector<string>> hashResult;
        
            for(auto str: strs){
                auto origstr = str;
                sort(str.begin(), str.end());
                hashResult[str].emplace_back(origstr);
            }
        
        for(auto &hr: hashResult){
            result.emplace_back(std::move(hr.second));
        }
        return result;
    }
};
#endif // SINGLENUMBER_H
