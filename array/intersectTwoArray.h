#ifndef INTERSECTTWOARRAY_H
#define INTERSECTTWOARRAY_H
#include <vector>
#include <set>

using namespace std;

class SolutionIntersect {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        if (nums2.size() < nums1.size())
            swap(nums2, nums1);

        multiset <int> set1;

        for(auto & n: nums1){
            set1.emplace(n);
        }

        vector <int> result;

        for(auto &n: nums2){
            if(set1.find(n) != set1.end()){
                result.push_back(n);
            }
        }

        return result;
    }
};
#endif // INTERSECTTWOARRAY_H
