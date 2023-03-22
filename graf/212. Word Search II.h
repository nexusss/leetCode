class Solution {
    array<int, 4> directX = {1, 0, -1, 0};
    array<int, 4> directY = {0, 1, 0, -1};
    
    struct TrieNode{
        array<TrieNode *, 26> childs;
        
        bool isEnd = false;
        string word;
        
        bool exist(char c){
            return childs[c - 'a'] != nullptr;
        }
        
        TrieNode* get(char c){
            return childs[c - 'a'];
        }
        
        TrieNode* put(char c){
            
            TrieNode* res = nullptr;
            
            if (exist(c)){
                res = get(c);
            }
            else{
                res = new TrieNode();
                childs[c - 'a'] = res;
            }
            
            return res;
        }
    };
    TrieNode *root = nullptr;
    unordered_set <string> alreadyadded;
    
public:
  
    
    void dfs(const vector<vector<char>>& board, vector <vector <bool>> &visited, vector<string> &result, int x, int y, TrieNode * root){
        if (root->isEnd){
            if (alreadyadded.find(root->word) == alreadyadded.end()){
                result.emplace_back(root->word);
                alreadyadded.emplace(root->word);
            }
        }

        visited[x][y] = true;
        
        for (size_t direct = 0; direct < directX.size(); ++direct){
            auto nextX = x + directX[direct];
            auto nextY = y + directY[direct];
            if (nextX >= 0 && nextX < board.size() && nextY >= 0 && nextY < board[0].size() && visited[nextX][nextY] == false && root->exist(board[nextX][nextY])){
                dfs(board, visited, result, nextX, nextY, root->get(board[nextX][nextY]));
            }
        }
        
        visited[x][y] = false;
        
        
    }
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        if (board.empty()){
            return {""};
        }
        
        int m = board.size();
        int n = board[0].size();
        vector<string> result;
        root = new TrieNode();
        
        vector <vector <bool>> visited(m, vector<bool>(n, false));
        for(auto &word: words){
            auto tmp = root;
            for(auto w: word){
                tmp = tmp->put(w);
            }
            tmp->isEnd = true;
            tmp->word = word;
        }
        
        for (int i = 0; i < m; ++i){
            for (int j = 0; j < n; ++j){
                if (root->get(board[i][j]) != nullptr ){
                    dfs(board, visited, result, i, j, root->get(board[i][j]));
                }
            }
        }
        
        return result;
    }
};