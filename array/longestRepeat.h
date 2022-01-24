#ifndef SINGLENUMBER_H
#define SINGLENUMBER_H
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

class SolutionSingleNumber {
public:
    int singleNumber(vector<int>& nums) {
        int res=0;
                for(int i =0;i<nums.size();i++){
                    res^=nums[i];
                }
                return res;

        /*if (nums.size() == 0)
                    return -1;
                else if(nums.size() == 1)
                    return nums.at(0);
                else if(nums.size() == 2)
                    return nums.at(1);
                else{
                    set <int> numbers;
                    for(auto & n: nums){
                        if (numbers.contains(n)){
                            numbers.erase(numbers.find(n));
                        }
                        else
                            numbers.emplace(n);
                    }
                    return *numbers.begin();
                }

        */
    }
};
#endif // SINGLENUMBER_H
