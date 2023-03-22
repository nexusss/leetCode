class Solution {
public:
    
    int lengthOfLIS(vector<int>& nums) {
        if (nums.empty()){
            return 0;
        }
        
        
        vector <int> subseqmp;
        
        for(size_t i = 0; i < nums.size(); ++i){
            
            if (subseqmp.empty() || subseqmp.back() < nums[i]){
                subseqmp.emplace_back(nums[i]);
            }
            else{
            
                auto it = lower_bound(subseqmp.begin(), subseqmp.end(), nums[i]);
                *it = nums[i];
            }
            
        }

        return subseqmp.size();
    }
};