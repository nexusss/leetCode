class Solution {
    void reverseStr(string& str)
    {
        int n = str.length();

        // Swap character starting from two
        // corners
        for (int i = 0; i < n / 2; i++)
            swap(str[i], str[n - i - 1]);
    }

    bool isPalindrom(const string &res){
        size_t left = 0;
        size_t right = res.size() - 1;

        while (left < right){
            if (res[left] != res[right]){
                return false;
            }
            ++left;
            --right;
        }
        return true;
    }


public:
    vector<vector<int>> palindromePairs(vector<string>& words) {

        unordered_map<string, int> mp;
        vector<vector<int>> res;

        for(int i = 0; i < words.size(); ++i){

            auto rstr = words[i];
            reverseStr(rstr);
            mp[rstr] = i;
        }

        for(int i = 0; i < words.size(); ++i){
            if(words[i] == ""){
                for(auto m: mp){
                    if(i != m.second){
                        if(isPalindrom(m.first)) {
                            res.push_back({i, m.second });
                        }
                        if(isPalindrom(m.first)) {
                            res.push_back({m.second, i });
                        }
                    }
                }
            }
            else {
                if(mp.find(words[i]) != mp.end()){
                    if(i != mp[words[i]]) {
                        res.push_back({i, mp[words[i]]});
                    }
                }

                for (size_t j = 1; j < words[i].size(); ++j) {
                    //cout << "i " << i << " j " << j << endl;
                    const string left = words[i].substr(0, j);
                    const string right = words[i].substr(j, words[i].size() - j);
                    //cout<< "l " << left << " r "<< right << endl;
                    {
                        if(mp.find(left) != mp.end() && isPalindrom(right) && mp[left] != i) {
                            res.push_back({i, mp[left]});     // 2) when j = 0, left = "", right = self, so here covers concatenate(self, "")
                        }

                        if(mp.find(right) != mp.end() && isPalindrom(left) && mp[right] != i) {
                            res.push_back({mp[right], i});
                        }

                    }
                    //cout << "end\n";
                }

            }
        }

        return res;
    }
};
