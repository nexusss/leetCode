class Solution {
    array<int, 4> directX = {1, 0, -1, 0};
    array<int, 4> directY = {0, 1, 0, -1};
public:
    bool dfs(const vector<vector<char>>& board, vector <vector <bool>> &visited, const string &word, size_t wordPos, int x, int y){
        if (wordPos + 1 == word.size()){
            return true;
        }
        
        visited[x][y] = true;
        
        for (size_t direct = 0; direct < directX.size(); ++direct){
            auto nextX = x + directX[direct];
            auto nextY = y + directY[direct];
            if (nextX >= 0 && nextX < board.size() && nextY >= 0 && nextY < board[0].size() && visited[nextX][nextY] == false && board[nextX][nextY] == word.at(wordPos + 1)){
                if (dfs(board, visited, word, wordPos + 1, nextX, nextY)){
                    return true;
                }
            }
            
        }
        
        visited[x][y] = false;
        
        return false;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        if (board.empty()){
            return word.empty() ? true: false;
        }
        
        int m = board.size();
        int n = board[0].size();
        vector <vector <bool>> visited(m, vector<bool>(n, false));
        
        for (int i = 0; i < m; ++i){
            for (int j = 0; j < n; ++j){
                if (board[i][j] == word.at(0)){
                    if (dfs(board, visited, word, 0, i, j)){
                        return true;
                    }
                }
            }
        }
        
        return false;
    }
};