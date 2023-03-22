#ifndef SINGLENUMBER_H
#define SINGLENUMBER_H
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
       vector<string> res;
        if (nums.empty()){
            return res;
        }
        for (size_t i = 0; i < nums.size();){
            size_t j = i + 1;
            string str = to_string(nums[i]);
            while (j < nums.size() && (nums[j] == nums[j-1] + 1)){
                ++j;
            }
            if (j - 1 != i){
                str += "->" + to_string(nums[j - 1]);
            }
            res.push_back(str);
            i = j;
        }
        return res;
    }
};
#endif // SINGLENUMBER_H
