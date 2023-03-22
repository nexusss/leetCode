#ifndef SINGLENUMBER_H
#define SINGLENUMBER_H
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
         sort(intervals.begin(), intervals.end());

        vector<vector<int>> merged;
        
        for(auto &interval: intervals){
            if (merged.empty()){
                merged.push_back(interval);
                continue;
            }
            if (merged.back()[1] < interval[0]){
                merged.push_back(interval);
            }
            else{
                if(merged.back()[1] < interval[1]){
                    merged.back()[1] = interval[1];
                }
            }
            
            
        }
        
        return merged;
    }
};
#endif // SINGLENUMBER_H
