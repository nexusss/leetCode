class Solution {
public:
        vector<int> maxSlidingWindow(vector<int>& nums, int k) {
            if (k < 1 || nums.empty()){
                return {};
            }
        
            auto comp = [](pair<int, int> &lhs, pair<int, int> &rhs){ 
                if (lhs.first == rhs.first){ 
                    return lhs.second > rhs.second; 
                }
                return lhs.first < rhs.first;
            };
            
        priority_queue <pair<int, int>, vector <pair<int, int>>,  decltype(comp)> maxValue(comp); //<value, position>
        for (size_t i = 0; i < k; ++i){
            maxValue.emplace(nums[i], i);
        }
                    
        size_t firstPos = 0;
        
        vector<int> result;
        
        result.emplace_back(maxValue.top().first);
        for (size_t i = k; i < nums.size(); ++i, ++firstPos){
            if (maxValue.top().first == nums[firstPos]){
                maxValue.pop();
                while (!maxValue.empty() && maxValue.top().second < firstPos){
                    maxValue.pop();
                }
            }
            
            maxValue.emplace(nums[i], i);
            result.emplace_back(maxValue.top().first);
        }
        
        
        return result;
        
    }
    
};