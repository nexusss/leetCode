class Solution {
    struct pair_hash {
        template <class T1, class T2>
        std::size_t operator () (const std::pair<T1,T2> &p) const {
            auto h1 = std::hash<T1>{}(p.first);
            auto h2 = std::hash<T2>{}(p.second);

            // Mainly for demonstration purposes, i.e. works but is overly simple
            // In the real world, use sth. like boost.hash_combine
            return h1 ^ h2;
        }
    };
    int64_t myround(double d)
    {
        return (d * 1000000) ;
    }

public:
        int maxPoints(vector<vector<int>>& points) {
        unordered_map<pair<int64_t, int64_t>, unordered_set<pair<int, int>, pair_hash>, pair_hash> mp;
        unordered_map<int64_t , unordered_set<pair<int, int>, pair_hash>> eq_x;
        size_t maxCount = 1;

        for(size_t i = 0; i + 1 < points.size(); ++i){
            auto y1 = points[i][0];
            auto x1 = points[i][1];

            for(size_t j = i + 1; j < points.size(); ++j){
                auto y2 = points[j][0];
                auto x2 = points[j][1];

                if(x2 - x1 != 0) {
                    int64_t tk = 0;
                    int64_t tb = 0;
                    
                    tk = myround((y2 - y1) / double(x2 - x1));
                    tb = myround(y2 - tk * x2);


                    mp[{tk, tb}].emplace(y2, x2);
                    mp[{tk, tb}].emplace(y1, x1);
                    maxCount = max(mp[{tk, tb}].size(), maxCount);
                }
                else{
                    eq_x[x2].emplace(y2,x2);
                    eq_x[x2].emplace(y1,x1);
                    maxCount = max(eq_x[x2].size(), maxCount);
                }

            }


        }
        return maxCount;
    }
};
