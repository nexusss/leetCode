#ifndef ISANAGRAM_H
#define ISANAGRAM_H
#include <string>

using namespace std;
class Solution {
public:
    bool isAnagram(string s, string t) {
        int arr[26] = {0};
        int n = s.length(), m = t.length();
        for(int i=0;i<n;i++) {
            arr[s[i]-'a']++;
        }
        for(int i = 0;i<m;i++){
            arr[t[i]-'a']--;
        }
        for(int i=0;i<26;i++){
            if(arr[i]!=0)return false;
        }
        return true;
    }
};
#endif // ISANAGRAM_H
