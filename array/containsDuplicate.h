#ifndef CONTAINSDUPLICATE_H
#define CONTAINSDUPLICATE_H

#include <vector>

class SolutionCD {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        for(int i = 1; i < nums.size(); ++i){
            if (nums.at(i - 1) == nums.at(i)){
                return true;
            }
        }
        return false;
    }
};

#endif // CONTAINSDUPLICATE_H
