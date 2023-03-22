class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        if (nums.empty() ){
            return 0;
        }
        
        sort(nums.begin(), nums.end());
        
        int l = nums.size() - 1;
        int r = nums.size() - 1;
        
        int result = 1;
        while(r >= 0){
            auto val = nums[r];
            
            //cout << "l " << nums[l] << " " << val << endl; 
            if (nums[l] - val > k){
                result++;
                l = r;
            }
            --r;
        }
        
        return result;
    }
};