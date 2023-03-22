class Solution {
    int M = 1e9+7;
public:
    void dfs(vector<vector<int>>& grid, int row, int column, vector <vector <int> > &pathNumbers){
    
        if (pathNumbers[row][column] > 1){
            return;
        
        }
    
        if (row + 1 < grid.size() && grid[row + 1][column] > grid[row][column]){
            dfs(grid, row + 1, column, pathNumbers);
            pathNumbers[row][column] += pathNumbers[row + 1][column] % M;
        }
        
        if (row - 1 >= 0 && grid[row - 1][column] > grid[row][column]){
            dfs(grid, row - 1, column, pathNumbers);
            pathNumbers[row][column] += pathNumbers[row - 1][column] % M;
        }
        
        if (column + 1 < grid[0].size() && grid[row][column + 1] > grid[row][column]){
            dfs(grid, row, column + 1, pathNumbers);
            //if (pathNumbers[row][column+1] > 100000)
            //cout << " pathNumbers[row][column] " << pathNumbers[row][column] << " " << pathNumbers[row][column + 1] << endl;
            pathNumbers[row][column] += pathNumbers[row][column + 1] % M;
        }
        
        if (column - 1 >= 0 && grid[row][column - 1] > grid[row][column]){
            dfs(grid, row, column - 1, pathNumbers);
            pathNumbers[row][column] += pathNumbers[row][column - 1] % M;
        }
        
    }
    
    int countPaths(vector<vector<int>>& grid) {
        if (grid.empty()){
            return 0;
        }
        
        int n = grid.size();
        int m = grid[0].size();
        
        vector <vector <int> > pathNumbers(n, vector<int>(m, 1));
        
        
        for(size_t i = 0; i < n; i++){
            for(size_t j = 0; j < m; j++){
            
                dfs(grid, i, j, pathNumbers);
            }
        
        }
        
        int64_t res = 0;
        
        for(size_t i = 0; i < n; i++){
            for(size_t j = 0; j < m; j++){
                res = (res + pathNumbers[i][j]) % M;
            }
        }
        return res;
    }
};