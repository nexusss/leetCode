class Solution {
    public:
    void backTrack(vector<int>& nums, int start, vector<int>& tmp, set<vector<int>> &res){
        if(start == nums.size()){

            return;
        }

        for(size_t i = start; i < nums.size(); ++i){
            if(tmp.back() <= nums[i]) {
                tmp.push_back(nums[i]);
                backTrack(nums, i + 1, tmp, res);
                if(tmp.size() > 1){
                    res.insert(tmp);
                }
                tmp.pop_back();
            }
        }


    }

    vector<vector<int>> findSubsequences(vector<int>& nums) {
        set<vector<int>> res;
        for(size_t i = 0; i < nums.size(); ++i){
            vector<int> tmp = {nums[i]};
            backTrack(nums, i + 1, tmp, res);
        }
        vector<vector<int>> rres;
        for(auto &r: res){
            rres.emplace_back(r);
        }
        return rres;
    }
};
