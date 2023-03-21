class MyHashSet {

    array<list<int>, 100> arr;
    size_t getPos(int key){
        auto hasher = hash<int>();
        return hasher(key) % arr.size();

    }
public:
    MyHashSet() {

    }

    void add(int key) {
        size_t pos = getPos(key);
        bool ok = true;
        for (auto iter = arr[pos].begin(); iter != arr[pos].end(); ++iter){
            if ((*iter) == key){
                ok = false;
                break;
            }

        }
        if (ok) {
            arr[pos].push_back(key);
        }
    }

    void remove(int key) {
        auto pos = getPos(key);
        for (auto iter = arr[pos].begin(); iter != arr[pos].end(); ++iter){
            if ((*iter) == key){
                arr[pos].erase(iter);
                break;
            }

        }
    }

    bool contains(int key) {
        auto pos = getPos(key);
        bool ok = false;
        for (auto &val: arr[pos]){
            if (val == key){
                ok = true;
                break;
            }

        }

        return ok;
    }
};