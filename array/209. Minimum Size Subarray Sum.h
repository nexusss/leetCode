class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        if(nums.empty())
            return 0;
        
        int sum = 0;
        int minLen = numeric_limits<int>::max();
        
        for (int l = 0, r = 0; r < nums.size(); ++r){
            sum += nums[r]; 
            
            while (sum >= target){
                /*if (sum >= target){
                    minLen = min(minLen, r - l + 1);
                }*/
                minLen = min(minLen, r - l + 1);
                sum -= nums[l];
                ++l;
                
            }
            
            
        }
        
        return minLen > nums.size() ? 0 : minLen;
    }
};