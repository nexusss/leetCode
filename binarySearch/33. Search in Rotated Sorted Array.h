class Solution {
public:
    int findMin(vector<int>& nums) {
        if (nums.size() == 1){
            nums[0];
        }
        int l = 0;
        int r = nums.size() - 1;
        
        while (l < r){
            int mid = l + (r - l) / 2;
            //cout << "mid" << mid << " " << l << " " << r << endl;
            if(nums[l] > nums[r] ){
                if (nums[mid] < nums[r]){
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
};