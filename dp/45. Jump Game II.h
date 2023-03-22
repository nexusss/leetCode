class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.size() < 2){
            return 0;
        }
        
        
        
        int jump = 0;
        int right = nums.size() - 1;
        
        while (right > 0){
            int canreach = nums[0];
            for(int i = 0; i <= right; ++i){
                
                    //cout << canreach << " i " << i << " j " << jump << endl;


                    canreach = max(canreach, nums.at(i) + i);
                
                
                if (canreach >= right){
                    jump++;
                    right = i;
                    
                    break;
                }
            }
            
        }
        
        
        
        return jump;
    }
};