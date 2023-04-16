class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
         if(beginWord == endWord){
             return 0;
         }
         unordered_map<string, bool> mp;

         for(auto &w: wordList){
             mp.emplace(w, false);
         }

         if(mp.find(endWord) == mp.end()){
            return 0;
         }

         queue<pair<string, int>> q;

         q.emplace(beginWord, 1);

        while(!q.empty()){
            auto top = q.front();
            if(top.first == endWord){
                return top.second;
            }

            for(size_t i = 0; i < beginWord.size(); ++i){
                auto tmp = top.first[i];
                for(auto c = 'a'; c <= 'z'; ++c){
                    if(top.first[i] != c){
                        
                        top.first[i] = c;
                        auto find = mp.find(top.first);
                        if(find != mp.end() and find->second == false){
                            q.emplace(top.first, top.second + 1);
                            find->second = true;
                        }
                        
                    }
                }
                top.first[i] = tmp;
            }

            q.pop();
        }
        return 0;
    }

};