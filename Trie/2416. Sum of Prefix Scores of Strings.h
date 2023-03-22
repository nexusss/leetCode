class Solution {
    struct TrieNode{
        array<TrieNode *, 26> childs;
        int counter = 0;
        
        bool exist(char c){
            return childs[c - 'a'] != nullptr;
        }
        
        TrieNode* get(char c){
            return childs[c - 'a'];
        }
        
        TrieNode* put(char c){
            
            TrieNode* res = nullptr;
            
            if (exist(c)){
                res = get(c);
            }
            else{
                res = new TrieNode();
                childs[c - 'a'] = res;
            }
            
            childs[c - 'a']->counter++; 
            return res;
        }
    };
    
    
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        TrieNode *trie = new TrieNode();
        
        for (const auto &word: words){
            auto root = trie;
            for(auto c: word){
                root = root->put(c);
            }
        }
        
        vector<int> result;
        
        for (const auto &word: words){
            int counter = 0;
            auto root = trie;
            for(auto c: word){
                auto tmp = root->get(c);
                counter += tmp->counter;
                root = tmp;
            }
            
            result.emplace_back(counter);
        }
        
        return result;
    }
};