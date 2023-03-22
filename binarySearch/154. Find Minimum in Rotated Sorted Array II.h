class Solution {
public:
    
    int binarySearch(const vector<int>& nums, int l, int r){
        while(l < r){
            int mid = l + (r - l) / 2;
            if (nums[l] >= nums[r]){
                if (nums[l] == nums[r]){
                    return min(binarySearch(nums, l, mid), binarySearch(nums, mid + 1, r));
                }
                else if (nums[mid] <= nums[r]){
                    r = mid;
                }
                else{
                    l = mid + 1;
                }
            }
            else{
                r = l;
            }
        }
        
        return nums[l];
    }
    
    int findMin(vector<int>& nums) {
        if (nums.empty() ){
            return -1;
        }
        
        int l = 0;
        int r = nums.size() - 1;
        
        return binarySearch(nums, 0, nums.size() - 1);
    }
};