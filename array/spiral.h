#ifndef SINGLENUMBER_H
#define SINGLENUMBER_H
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

class Solution {
    
    
    
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        
        if (matrix.size() == 0)
            return result;
        
        if (matrix.at(0).size() == 0)
            return result;
        
        size_t R = matrix.size(), C = matrix[0].size();
        int64_t k = 0, j = 0;
        
        int64_t dk[4] = {0,1,0,-1};
        int64_t dj[4] = {1,0,-1,0};
        size_t di = 0;
        
        
        vector<vector<bool>> seen(R, vector<bool>(C, false));
        
        for(size_t i = 0; i < C*R; ++i){
            result.push_back(matrix.at(k).at(j));
            seen[k][j] = true;
            
            auto tk = k + dk[di];
            auto tj = j + dj[di];
            if (tk >= 0 && tk < R && tj >= 0 && tj < C && !seen.at(tk).at(tj)){     
                k += dk[di];
                j += dj[di];
            }
            else{
                if (di == 3)
                    di = 0;
                else
                    ++di;
            
                k += dk[di];
                j += dj[di];
            }
        
        }
        
        return result;
    }
};
#endif // SINGLENUMBER_H
