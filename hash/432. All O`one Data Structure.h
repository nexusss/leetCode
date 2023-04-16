class AllOne {
    multimap<size_t, string> mm;
    unordered_map<string, decltype(mm.begin())> mp;
    
public:
    AllOne() {
    }
    
    void inc(string key) {
        auto find = mp.find(key);
        size_t count = 1;
        if(find != mp.end()){
            auto iter = find->second;
            count = iter->first;
            mm.erase(iter);
            ++count;
            
        }
        auto iter = mm.emplace(count, key);
        mp[key] = iter;
        
    }
    
    void dec(string key) {
        auto find = mp.find(key);
        if(find == mp.end()){
            return;
        }

        
        auto iter = mp[key];
        auto count = iter->first;
        --count;
        mm.erase(iter);

        if(count > 0){
            auto niter = mm.emplace(count, key);
            mp[key] = niter;
        }
        else{
            mp.erase(key);
        }

    }
    
    string getMaxKey() {
        if(mm.empty()){
            return "";
        }
        return mm.rbegin()->second;
    }
    
    string getMinKey() {
        if(mm.empty()){
            return "";
        }
        return mm.begin()->second;
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */