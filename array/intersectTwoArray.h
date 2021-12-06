#ifndef INTERSECTTWOARRAY_H
#define INTERSECTTWOARRAY_H
#include <vector>
#include <unordered_map>

using namespace std;

class SolutionIntersect {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        if (nums2.size() < nums1.size())
            swap(nums2, nums1);

        unordered_map <int, int> set1;

        for(auto & n: nums1){
            set1[n]++;
        }

        vector <int> result;

        for(auto &n: nums2){
            if(set1[n] > 0){
                           result.push_back(n);
                           set1[n]--;
                       }
        }

        return result;
    }
};
#endif // INTERSECTTWOARRAY_H
