#ifndef FINDTWOSUM_H
#define FINDTWOSUM_H
#include <vector>
#include <algorithm>
#include <unordered_map>

class Solution {
        
public:

    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> output;
          sort(nums.begin(), nums.end());
          for (int i = 0; i < nums.size(); ++i) {
            if (i != 0 && nums[i] == nums[i - 1]) continue;
            unordered_set<int> seen;
            for (int j = i + 1; j < nums.size(); ++j) {
              if (seen.count(-nums[i] - nums[j])) {
                output.push_back({nums[i], nums[j], -nums[i] - nums[j]});
                // Skip duplicates
                while (nums[j+1] == nums[j] && j + 1 < nums.size()) ++j;
              }
              seen.insert(nums[j]);
            }
          }
          return output;
    }
};


#endif // FINDTWOSUM_H
