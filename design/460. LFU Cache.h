class LFUCache {

    struct Key{
        int val;
        int key;
        Key(int key, int val): val(val), key(key){}
    };

    unordered_map<int, list <Key>> mpfreq; // freq, counter
    unordered_map<int, decltype(mpfreq.begin()->second.begin())> mpfreqpos; //key, mpfreqpos
    unordered_map<int, int> mp; //key, freq


    int capacity = 0;
    int size = 0;
    int minFreq = 1;
public:
    LFUCache(int capacity):capacity(capacity) {

    }

    int get(int key) {
        auto find = mp.find(key);
        if(find == mp.end()){
            return -1;
        }
        auto freqposfind = mpfreqpos.find(key);
        if(freqposfind == mpfreqpos.end()){
            cout << "error";
            return -1;
        }

        auto val = freqposfind->second->val;
        mpfreq[find->second].erase(freqposfind->second);//


        find->second++;

        mpfreq[find->second].emplace_back(key, val);//
        mpfreqpos[key] = --mpfreq[find->second].end();
        if(mpfreq[minFreq].empty()){
            minFreq++;
        }
        return val;
    }

    void put(int key, int value) {

        auto find = mp.find(key);
        if(find == mp.end()){
            if (size  == capacity) {
                //erase
                auto minkey = mpfreq[minFreq].begin()->key;
                mpfreq[minFreq].pop_front();
                mp.erase(minkey);
                mpfreqpos.erase(minkey);
                --size;

            }

            ++size;
            mp[key]++;
            minFreq = 1;
            mpfreq[minFreq].emplace_back(key, value);
            mpfreqpos[key] = --mpfreq[minFreq].end();

        }
        else{
            mpfreqpos[key]->val = value;
            get(key);
        }
    }
};