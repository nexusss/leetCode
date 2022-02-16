#ifndef VALIDATEBINARY_H
#define VALIDATEBINARY_H
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    struct Point{
        size_t x;
        size_t y;
    };
public:
    int numIslands(vector<vector<char>>& grid) {
        size_t counter = 0;
        
        if (grid.size() == 0)
            return counter;
        
        vector<vector<bool>> visited;
        
        visited.resize(grid.size());
        for (auto& v:visited){
            v.resize(grid.at(0).size(),false);
        }
        
        for(size_t i = 0; i < grid.size(); ++i){
            for(size_t j = 0; j < grid.at(i).size(); ++j){
                //cout << grid.at(i).at(j) << !visited.at(i).at(j) << endl;
                if(grid.at(i).at(j) == '1' && !visited.at(i).at(j)){
                    stack<Point> st;
                    st.push({i,j});
                    visited[i][j] = true;
                    counter++;
                    while(!st.empty()){
                        auto val = st.top();
                        st.pop();
                        
                        if (val.x > 0 && grid.at(val.x-1).at(val.y) == '1' && !visited.at(val.x-1).at(val.y)){
                            st.push({val.x-1, val.y});
                            visited[val.x-1][val.y] = true;
                        }
                        if (val.x < grid.size()-1 && grid.at(val.x+1).at(val.y) == '1' && !visited.at(val.x+1).at(val.y)){
                            st.push({val.x+1, val.y});
                            visited[val.x+1][val.y] = true;
                        }
                        if (val.y > 0 && grid.at(val.x).at(val.y-1) == '1' && !visited.at(val.x).at(val.y-1)){
                            st.push({val.x, val.y-1});
                            visited[val.x][val.y-1] = true;
                        }
                        if (val.y < grid.at(val.x).size() - 1 && grid.at(val.x).at(val.y+1) == '1' && !visited.at(val.x).at(val.y+1)){
                            st.push({val.x, val.y+1});
                            visited[val.x][val.y+1] = true;
                        }
                    }
                
                }
            }
                
        }
        return counter;
        
    }
};
#endif // VALIDATEBINARY_H
