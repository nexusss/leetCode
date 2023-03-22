class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        
        if (obstacleGrid.size() == 0){
            return 0;
        }
        
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        
        vector<vector<int>> dp(m, vector<int>(n, 1));
        
        
        
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(obstacleGrid[i][j] == 1){
                    dp[i][j] = 0;
                }
                
                if (j > 0 and dp[i][j - 1] == 0){
                    dp[i][j] = 0;
                }
                
                if (i > 0 and dp[i - 1][j] == 0){
                    dp[i][j] = 0;
                }
            }
        }
        
        for(int i = 1; i < m; ++i){
            for(int j = 1; j < n; ++j){
                if(obstacleGrid[i][j] == 1){
                    dp[i][j] = 0;
                }
                else{
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                }
            }
        }
        return dp[m - 1][n - 1];
        
    }
};