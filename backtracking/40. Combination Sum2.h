class Solution {
public:
    void backtracking(vector<int>& candidates, int target,int sum, int startPos, vector<vector<int>> &result, vector<int> candidate){
        if (startPos == candidates.size()){
            return;
        }
        for (size_t i = startPos; i < candidates.size(); ++i){
            if (i > startPos && candidates[i] == candidates[i - 1]) continue;
            sum += candidates[i];
            candidate.emplace_back(candidates[i]);

            if (sum < target){
                backtracking(candidates, target, sum, i + 1, result, candidate);
            }
            else if (sum == target){
                result.emplace_back(candidate);
            }
            
            sum -= candidates[i];
            candidate.pop_back();
        }
        
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        
        vector<vector<int>> result;
        backtracking(candidates, target, 0, 0, result, {});
        return result;
    }
};