class Solution {
public:
    bool canJump(vector<int>& nums) {
        if (nums.empty()){
            return false;
        }
        
        vector<int> canreach(nums.size());
        canreach[0] = nums[0];
        
        for(int i = 1; i < nums.size(); ++i){
            //cout << canreach[i - 1] << " i " << i << endl;
            if (canreach[i - 1] >= i){
                canreach[i] = max(canreach[i - 1], nums.at(i) + i);
            }
            else{
                return false;
            }
        }
        
        return true;
    }
};