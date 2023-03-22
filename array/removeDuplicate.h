#ifndef SINGLENUMBER_H
#define SINGLENUMBER_H
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty())
            return 0;
        
        vector<int> result(nums.size());
        result[0] = nums.at(0);
        int k = 0;
        for (int i = 1; i < nums.size(); ++i){
            if (nums.at(i) != result[k]){
                ++k;
                result[k] = nums.at(i);
            }
            
        }
        
        swap(result, nums);
        
        return k + 1;
    }
};#endif // SINGLENUMBER_H
