class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map <int,int>mp ;
        int sum = 0;
        int res = 0;
        int rem = 0;
        for(int i = 0 ; i <nums.size();i++)
        {
            cout << "nums[i] " << nums[i] << endl;
            sum = sum + nums[i];
            cout << "sum " << sum << endl;
            if(sum == k)
                res +=1;
            rem = sum -k;
            cout << "rem " << rem << " " << mp[rem] << endl;
            if(mp[rem]){
                res = res + mp[rem];
                cout << "res " << res << endl;
            }
            mp[sum]++;
            for (auto &m: mp){
                cout << "mp " << m.first << " " << m.second << endl;
            }
        }
        return res;
    }
};