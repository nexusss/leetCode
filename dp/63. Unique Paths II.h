class Solution {
   
    
public:

    
    int uniquePaths(int m, int n) {
        if (m == 0 || n == 0){
            return 1;
        }
        
        
        vector<vector<size_t>> dp(m, vector<size_t>(n, 0));
        
        dp[0][0] = 1;
        
        for(int i = 1; i < m; ++i){
            for(int j = 1; j < n; ++j){
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }

        return dp[m - 1][n - 1];
        
    }
};