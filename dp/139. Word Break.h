class Solution {
public:
    bool helper(const string &s, size_t right, unordered_set<string> &mp){
        if (right == s.size()){
            return true;
        }
        //cout << "helper " << right << endl;
        
        for(size_t i = right; i < s.size(); i++){
            //cout << "sub " << s.substr(right, i - right + 1) << " i " << i << endl;
            if (mp.find(s.substr(right, i - right + 1)) != mp.end()){
                auto res = helper(s, i + 1, mp);
                if (res){
                    return true;
                }
            }
        }
        return false;
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> mp;
        //cout << s.substr(4, 4) << " " << s.size() << endl;
        
        for(auto &word: wordDict){
            mp.emplace(word);
        }
        return helper(s,0,mp);
    }
};