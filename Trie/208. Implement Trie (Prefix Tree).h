class Trie {
    struct TrieNode{
        array<TrieNode *, 26> links;
        bool end = false;
        
        void put(char c, TrieNode *node){
            links[c - 'a'] = node;
            
        }
        
        TrieNode* get(char c){
            return links[c - 'a'];
        }
        
        bool contains(char c){
            return links[c - 'a'] != nullptr;
        }
        bool isEnd(){
            return end;
        }
        
        void setEnd(){
            end = true;
        }
    };
    TrieNode *root;
public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        auto tmpRoot = root;
        
        for (auto &w: word){
            if (!tmpRoot->contains(w)){
                tmpRoot->put(w, new TrieNode());
            }
            tmpRoot = tmpRoot->get(w);
        }
        tmpRoot->setEnd();
    }
    
    TrieNode* searchPrefix(const string &word){
        auto tmpRoot = root;
        for(auto &w: word){
            if (!tmpRoot->contains(w)){
                return nullptr;
            }
            tmpRoot = tmpRoot->get(w);
        }
        
        return tmpRoot;
    }
    
    bool search(string word) {
        auto node = searchPrefix(word);
        return node != nullptr && node->isEnd();
    }
    
    bool startsWith(string prefix) {
        
        
        return searchPrefix(prefix) != nullptr;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */