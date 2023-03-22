#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int subarraySum(vector<int>& nums, int k) {
    unordered_map <int,int> mp;

    int sum = 0;
    int res = 0;

    for(int i = 0 ; i <nums.size();i++)
    {
        sum += nums[i];
        if(sum == k)
            res +=1;

        int rem = sum -k;
        if(mp[rem])
            res += mp[rem];
        mp[sum]++;
    }



    return res;
}

int main()
{
    vector<int> nums = {1,2,3,4,5,2,1};
    subarraySum(nums,3);
    cout << "Hello World!" << endl;
    return 0;
}
