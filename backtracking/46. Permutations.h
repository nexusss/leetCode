class Solution {
public:
    void backTracking(vector<int>& nums, int l, int r,vector<vector<int>> &result){
        if (l == r){
            result.emplace_back(nums);
            return;
        }
        
        for(auto i = l; i <= r; ++i){
            swap(nums[l], nums[i]);
            backTracking(nums,l + 1, r, result);
            swap(nums[l], nums[i]);
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        
        backTracking(nums,0, nums.size() - 1, result);
        
        return result;
    }
};