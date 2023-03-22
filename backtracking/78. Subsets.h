class Solution {
public:
    
    void backtracking(const vector<int>& nums, vector<int> comb, int pos, vector<vector<int>> &result){
        result.emplace_back(comb);
        

        
        for (int i = pos; i < nums.size(); ++i){    
            comb.emplace_back(nums[i]);
            backtracking(nums, comb, i + 1, result);
            comb.pop_back();
        }
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result = {};
        
        backtracking(nums, {}, 0, result);
        
        return result;
    }
};