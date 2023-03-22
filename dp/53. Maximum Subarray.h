class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.empty()){
            return 0;
            
        }
        
        if(nums.size() == 1){
            return nums[0];
        }
        
        
        
        vector <int> memo(nums.size());
        memo[0] = nums[0];
        int sum = memo[0];
        
        for(size_t i = 1; i < nums.size(); ++i){
            memo[i] = nums[i] + (memo[i - 1] > 0 ? memo[i - 1] : 0);
            
            sum = max(sum, memo[i]);
        }
                
        return sum;
    }
};