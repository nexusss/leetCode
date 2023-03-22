class WordDictionary {
    struct TrieNode{
        array<TrieNode *, 26> childs;
        bool isEnd;
        
        void put(char c, TrieNode *child){
            childs[c - 'a'] = child;
        }
        
        bool contains(char c){
            //cout << "char " << c << endl;
            return childs[c - 'a'] != nullptr;
        }
        
        TrieNode *get(char c){
            return childs[c - 'a'];
        }
        
        void setEnd(){
            isEnd = true;
        }
        
        bool end(){
            return isEnd;
        }
    };
    
    TrieNode *root = nullptr;
    
public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        auto tmp = root;
        for(auto w: word){
            if (!tmp->contains(w)){
                tmp->put(w, new TrieNode());
            }
            tmp = tmp->get(w);
        }
        tmp->setEnd();
    }
    
    TrieNode *searchPrefix(const string &word, TrieNode *tmp, size_t startPos){
        //cout << "word " << word << endl;

        
        for(size_t i = startPos; i < word.size(); ++i){
            auto w = word[i];
            if (w != '.'){
                //cout << "w " << w << endl;
                if (tmp->contains(w)){
                    tmp = tmp->get(w);
                }
                else{
                    return nullptr;
                }
            }
            else{
                
                for (auto &child: tmp->childs){
                    if(child == nullptr){
                        continue;
                    }
                    auto res = searchPrefix(word ,child, i + 1);
                    if(res != nullptr && res->end()){
                        return res;
                    }
                }
                
                return nullptr;
            }
        }
        
        return tmp;
    }
    
    bool search(string word) {
        auto res = searchPrefix(word, root, 0);
        return res != nullptr && res->end();
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */