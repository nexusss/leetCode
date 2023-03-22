#ifndef SINGLENUMBER_H
#define SINGLENUMBER_H
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        
        stack<int> tmp;
        
        for(size_t i = 0, k = 0; i < pushed.size(); ++i){
            
            tmp.push(pushed[i]);
                
            while(!tmp.empty()){
                if (tmp.top() == popped[k]){
                    tmp.pop();
                    ++k;
                }
                else{
                    break;
                }
                
            }    
        }
        
        return tmp.empty();
        
        
    }
};
 #endif // SINGLENUMBER_H
