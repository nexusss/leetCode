#ifndef FINDTWOSUM_H
#define FINDTWOSUM_H
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class SolutionFTS {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map <int, int> numsHash;
        for(int i = 0; i < nums.size(); ++i){
            auto findValueInHash = target - nums.at(i);
            auto findIter = numsHash.find(findValueInHash);
            if (findIter != numsHash.end()){
                return {findIter->second, i};
            }
            numsHash.emplace(nums.at(i), i);
        }
        return {0};
    }
};

#endif // FINDTWOSUM_H
