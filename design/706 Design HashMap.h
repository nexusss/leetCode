class MyHashMap {
    array<list<pair<int, int>>, 100> arr;
    size_t getPos(int key){
        auto hasher = hash<int>();
        return hasher(key) % arr.size();

    }
public:
    MyHashMap() {

    }

    void put(int key, int value) {
        size_t pos = getPos(key);
        for (auto iter = arr[pos].begin(); iter != arr[pos].end(); ++iter){
            if ((*iter).first == key){
                (*iter).second = value;
                return ;
            }

        }

        arr[pos].emplace_back(key, value);

    }

    int get(int key) {
        size_t pos = getPos(key);
        for (auto iter = arr[pos].begin(); iter != arr[pos].end(); ++iter){
            if ((*iter).first == key){
                return (*iter).second;
            }

        }
        return -1;
    }

    void remove(int key) {
        auto pos = getPos(key);
        for (auto iter = arr[pos].begin(); iter != arr[pos].end(); ++iter){
            if ((*iter).first == key){
                arr[pos].erase(iter);
                break;
            }

        }
    }
};