#ifndef SINGLENUMBER_H
#define SINGLENUMBER_H
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if (nums.size() == 0)
            return 0;
        
        int result = 0;
        auto last = nums.size() - 1;
        for (int i = last; i >= 0; --i){
            cout << "i" << i << endl;
            if (nums.at(i) == val){
                result++;
                if (i != last){
                    swap(nums[i], nums[last]);
                    
                }
                last--;
            }
        }
        cout << result << endl;
        return nums.size() - result;
    }   
};#endif // SINGLENUMBER_H
