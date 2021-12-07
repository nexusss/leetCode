#ifndef MOVEZERO_H
#define MOVEZERO_H
class SolutionMZ {
public:
    void moveZeroes(vector<int>& nums) {

        for(int i = 0, endZero = 0; endZero < nums.size();){
            if(nums.at(endZero) == 0){
                ++endZero;
                continue;
            }
            else if (i != endZero){
                swap(nums[i],nums[endZero]);
            }
            ++i;
            ++endZero;
        }
    }
};
#endif // MOVEZERO_H
