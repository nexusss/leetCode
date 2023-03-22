class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int maxLen = 0;
        
        if (nums.empty()){
            return maxLen;
        }
        
        
        priority_queue <pair<int, int>, vector<pair<int,int>>> maxhp;
                priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minhp;
        
        for(int l = 0, r = 0; r < nums.size(); ++r){
            maxhp.emplace(nums[r], r);
            minhp.emplace(nums[r], r);
            if (maxhp.top().first - minhp.top().first <= limit){
                maxLen = max(maxLen, r - l + 1);
                //cout << "l " << l << " r " << r << endl;
            }
            else while ( maxhp.top().first - minhp.top().first > limit ){
                if (nums[l] == maxhp.top().first){
                    maxhp.pop();
                    while(maxhp.top().second < l){
                        maxhp.pop();
                    }
                }
                if (nums[l] == minhp.top().first){
                    minhp.pop();
                    while(minhp.top().second < l){
                        minhp.pop();
                    }
                }
                ++l;
            }
        
        }
        return maxLen;
    }
};