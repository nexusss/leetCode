class MapSum {
    unordered_map <string, int> mp;

    struct TrieNode{
        struct TrieNode *arr[27] = {nullptr};
        int val = 0;
    };


    TrieNode *root = new TrieNode();
public:
    MapSum() {
        
    }
    
    void insert(string key, int val) {
        auto cur = root;
        
        auto newVal = val - mp[key];

        cur->val += newVal;
        for(auto k: key){
            size_t index = k - 'a';
            if (cur->arr[index] == nullptr){
                cur->arr[index] = new TrieNode();
            }
            
            cur = cur->arr[index];
            cur->val += newVal;
        }

        mp[key] = val;

    }
    
    int sum(string prefix) {
        int result = 0;
        auto cur = root;
        bool find = true;
        for(auto p: prefix){
            size_t index = p - 'a';
            if (cur->arr[index] == nullptr){
                find = false;
                break;
            }
            cur = cur->arr[index];
        }
        if(find){
            result = cur->val;
        }

        return result;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */