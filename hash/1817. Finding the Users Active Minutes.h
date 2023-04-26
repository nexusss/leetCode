class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
                unordered_map<int, unordered_set<int>> mp;
        vector<int> res(k);

        for(auto &l: logs){
            auto find = mp.find(l[0]);
            if(find == mp.end()){
                mp[l[0]].insert(l[1]);
                res[0]++;
            }
            else{
                res[find->second.size() - 1]--;
                find->second.insert(l[1]);
                res[find->second.size() - 1]++;
            }
        }

        return res;
    }
};
