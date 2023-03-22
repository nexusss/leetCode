class Solution {
public:
    
    void backtracking(const vector<int>& candidates, int l, int sum, int target, vector<vector<int>> &result, vector<int> candidate){
  
        //cout << "back track " << l << " sum " << sum  << endl;
        if (l == candidates.size()){
            return;
        }
        
            sum += candidates[l];
            candidate.emplace_back(candidates[l]);
            if (sum < target){
                backtracking(candidates, l, sum, target, result, candidate);
            }
            
            else if (sum == target){
                result.emplace_back(candidate);
                return;
            }
            
                sum -= candidates[l];
                candidate.pop_back();
                backtracking(candidates, l + 1, sum, target, result, candidate);
                    
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> result;
        
            backtracking(candidates, 0, 0, target, result, {});

        return result;
        
    }
};