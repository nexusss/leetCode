class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string> res;

        for(auto &q:queries){

            for(auto &d: dictionary){
                auto delta = 0;
                for(size_t i = 0; i < q.size(); ++i){
                    if(q[i] != d[i]){
                        delta++;
                    }
                    if(delta > 2){
                        break;
                    }
                }
                if(delta <= 2){
                    res.push_back(q);
                    break;
                }
            }
        }
        return res;

    }
};