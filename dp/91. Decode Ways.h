class Solution {
public:
    
    int stringCounter(string &s, size_t pos, vector<int> &dp){
        if (pos == s.size()){
            
            
            return 1;
        }
        if (s[pos] == '0'){
            return 0;
        }
        
        if (dp[pos] != -1) return dp[pos];
        
        int result = stringCounter(s, pos + 1, dp);
        
        if (pos + 1 < s.size()){
            if (s[pos] == '1'){
                result += stringCounter(s, pos + 2, dp);
            }
            else if (s[pos] == '2'  && (s[pos+1] >= '0' && s[pos + 1] <= '6')){
                result += stringCounter(s, pos + 2, dp);
            }
        }
        
        dp[pos] = result;
        return dp[pos];
    }
    
    int numDecodings(string s) {
        if (s.empty() ){
            return 0;
        }
        int result = 0;
        vector<int> dp (s.size(), -1);
        return stringCounter(s, 0, dp);
    }
};