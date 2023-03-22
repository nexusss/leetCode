#ifndef FINDTWOSUM_H
#define FINDTWOSUM_H
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.size() == 0){
            return {-1, -1};
        }
        int left = 0;
        int right = nums.size() - 1;
        int medium;
        while (left <= right){
            medium = left + (right - left) / 2;
            auto tmp = nums[medium];
            if (nums[medium] == target){
                left = medium;
                while(left >= 0 && nums[left] == target){
                    left--;
                }
                right = medium;
                while(right < nums.size() && nums[right] == target){
                    right++;
                }
                return {left + 1, right - 1};
            }
            else if(nums[medium] > target){
                right = medium - 1;
            }
            else if(nums[medium] < target){
                left = medium + 1;
            }
        }
        
        return {-1,-1};
    }
};
#endif // FINDTWOSUM_H
