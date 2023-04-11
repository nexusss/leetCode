    struct hashFunction
    {
        size_t operator()(const pair<bool,
                bool> &x) const
        {
            return x.first ^ x.second;
        }
    };

    unordered_set<pair<int, int>, hashFunction> res;

    //pair as hash