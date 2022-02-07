#ifndef FINDTWOSUM_H
#define FINDTWOSUM_H
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
    void findTwoSum(vector<int>& nums, size_t dontCheck, int target, vector<vector<int>> &res){
        unordered_map <int, int> numshash;
        
        for(int i = dontCheck + 1; i < nums.size(); ++i){
            
            auto result = target - nums.at(i);
            auto findIter = numshash.find(nums.at(i));
            if (findIter != numshash.end()){
                res.push_back({findIter->second, nums.at(i), target * -1});
                while ( i + 1 < nums.size() and nums.at(i) == nums.at(i + 1))
                    ++i;
            }
            numshash.emplace(result, nums.at(i));
        }
    }
    
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(begin(nums), end(nums));
        if (nums.size() >= 3){
            for (int i = 0; i < nums.size() && nums[i] <= 0; ++i){
                if (i == 0 || nums[i - 1] != nums[i]) {
                    findTwoSum(nums, i, nums.at(i) * -1, result);
                    
                }
            }
        }
        
        return result;
    }
};

#endif // FINDTWOSUM_H
