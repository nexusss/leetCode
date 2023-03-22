class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if (nums.empty()){
            return ;    
        }
        
        while (k >= nums.size())
            k -= nums.size();
        
        vector <int> result(nums.size());
        
        for (int i = nums.size() - k,j = 0 ; i < nums.size(); ++i, ++j){
            result[j] = nums[i];
            
        }
        
        for (int i = 0, j = k; i < nums.size() - k; ++i, ++j){
            result[j] = nums[i];
        }
        swap(nums, result);
    }
};