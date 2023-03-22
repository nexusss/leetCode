class Solution {
public:
    int minDistance(string word1, string word2) {
        if (word1.empty()){
            return word2.size();
        }
        
        if (word2.empty()){
            return word1.size();
        }
        
        int m = word1.size();
        int n = word2.size();
        
        vector<vector<int>> distance(m + 1, vector<int>(n + 1, 0));

        for(int i = 1; i <= m; ++i){
            distance[i][0] = i;    
        }
        
        for(int j = 1; j <= n; ++j){
            distance[0][j] = j;    
        }
        
        for(int i = 1; i <= m; ++i){
            for(int j = 1; j <= n; ++j){
                int cost = word1[i - 1] != word2[j - 1] ? 1 : 0;
                
                auto minDist = min(distance[i - 1][j] + 1, distance[i][j - 1] + 1);
                distance[i][j] = min(minDist, distance[i - 1][j - 1] + cost);
                
                
            }
            
        }
        
        return distance[m ][n];
    }
};