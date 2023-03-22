class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, vector<int>> hash;
        
        int maxFreq = 0;
        
        for(size_t i = 0; i < nums.size(); ++i){
            hash[nums[i]].push_back(i);
            if (maxFreq < hash[nums[i]].size()){
                maxFreq = hash[nums[i]].size();
            }
        }
        
        int minDistance = numeric_limits<int>::max();
        for (auto distk: hash){
            auto dist = distk.second;
            
            if (dist.size() == maxFreq){
                minDistance = min(minDistance, dist.back() - dist.front() + 1);
            }
            
        }
        
        return minDistance;
    }
};