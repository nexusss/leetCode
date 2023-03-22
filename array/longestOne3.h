#ifndef SINGLENUMBER_H
#define SINGLENUMBER_H
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int longestRepeat = 0;
        int maxLongenstRepeat = 0;
        int l = 0;
        int r = 0;
        int tmpK = k;
        while( r < nums.size()){
            if (nums[r] != 1){
               //cout << nums[r] << " r " << r << " k " << tmpK << endl;
                if (tmpK > 0){
                    tmpK--;
                }
                else{
                    //cout << " l " << l << " r " << r << " k " << tmpK << " max " << maxLongenstRepeat << endl;
                    maxLongenstRepeat = max(maxLongenstRepeat, r - l);
                    while(nums[l] == 1){
                        l++;
                    }
                    
                    //tmpK++;
                    l++;
                    //cout << " l " << l << " r " << r << " k " << tmpK << " max " << maxLongenstRepeat  << endl;
                }
            }
            r++;
        }
        maxLongenstRepeat = max(maxLongenstRepeat, r - l);
        return maxLongenstRepeat;
    }
};
#endif // SINGLENUMBER_H
