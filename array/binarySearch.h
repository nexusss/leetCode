#ifndef SINGLENUMBER_H
#define SINGLENUMBER_H
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

class Solution {
public:
    void binarySearch(vector<int> input, int val){
    int left = 0;
    int right = input.size();
    int medium;
    vector<int> res;
    res.reserve(4);
    while (left <= right){
        medium = left + (right - left) / 2;
        auto tmp = input[medium];
        if (input[medium] == val){
            break;
        }
        else if(input[medium] > val){
            right = medium - 1;
        }
        else if(input[medium] < val){
            left = medium + 1;
        }
    }

    return res;
}
};#endif // SINGLENUMBER_H
