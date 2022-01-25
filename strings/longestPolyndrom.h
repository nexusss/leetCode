class Solution {
public:
    int isPalindrome(string &s, int left, int right) {
        while (left >= 0 and right < s.size() and s[left] == s[right]){
            left--;
            right++;
        }
        
        return right - left - 1;
    }
    //"aacabdkacaa"

    string longestPalindrome(string s) {
        if (s.size() < 2) return s;
        
        int MaxLenPalindrome = 0;
        int start = 0, end = 0;
        for (int i = 0; i < s.size() - 1; ++i){
            int len1 = isPalindrome(s, i, i);
            int len2 = isPalindrome(s, i, i + 1);
            int len = max(len1, len2);
            
            if (len > 0 and len > MaxLenPalindrome){
                MaxLenPalindrome = len;
                start = i - (len - 1)/2;
                end = i + len / 2;
            }
        }        
        return s.substr(start, MaxLenPalindrome);
    }
};