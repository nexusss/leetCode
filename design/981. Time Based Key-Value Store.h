class TimeMap {

    unordered_map<string, map<int, string> > mp;

public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key][timestamp] = value;
    }
    
    string get(string key, int timestamp) {

        auto keyFind = mp.find(key);

        if (keyFind == mp.end()){
            return "";
        }

        auto &tm = keyFind->second;
        if (tm.size() == 0){
            return "";
        }


        auto end = tm.end();
        end--;
        if (end->first <= timestamp){
            //cout << " 0 " << timestamp << " " << end->second << endl;
            return end->second;
        }
        else if(tm.begin()->first <= timestamp){
            //cout << timestamp << endl;
            auto find = tm.upper_bound(timestamp);
            find--;
            if (find != tm.end()){
                
                //cout << timestamp << " " << find->first << " " << find->second << endl;
                return find->second;
            }
        }

        return "";

    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */