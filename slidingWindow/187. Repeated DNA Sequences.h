class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string, bool> stringhash;
        vector<string> result;
        
        for(int l = 0, r = 9; r < s.size(); ++l, ++r){
                string tmps(s.begin() + l, s.begin() + r + 1);
                auto iter = stringhash.find(tmps);
                if (iter != stringhash.end()){
                    if (iter->second == false){
                        result.emplace_back(tmps);
                        iter->second = true;
                    }
                    
                }
                else{
                    stringhash.emplace(tmps, false);
                }
             
        }
        return result;
    }
};