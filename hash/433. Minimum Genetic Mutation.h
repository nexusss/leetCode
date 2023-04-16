class Solution {
    unordered_set <string> bs;
    struct S{
            string s;
            size_t pos;
            int res;
            S(const string &s, size_t pos, int res): s(s),pos(pos), res(res){} 
        };
public:
    void mutate(char c, string s, size_t pos, int res, queue<S> &q ){
            if (pos == s.size()){
                return ;
            }

            if(s[pos] == c){
                return ;
            }

            s[pos] = c;
            if(bs.find(s) != bs.end()){
                q.emplace(s, pos, res + 1);
            }
    }

    int minMutation(string startGene, string endGene, vector<string>& bank) {
        if(startGene == endGene){
            return 0;
        }

        auto delta = 0;
        for(size_t i = 0; i < startGene.size(); ++i){
            if(startGene[i] != endGene[i]){
                ++delta;
            }
        }

        if(delta > bank.size()){
            return -1;
        }

        for(auto b: bank){
            bs.insert(b);
        }

        if(bs.find(endGene) == bs.end()){
            return -1;
        }

        queue<S> q;

        q.emplace(startGene, 0, 0);

        int minres = 0;
        
        while(!q.empty()){
            auto top  = q.front();

            if(top.s == endGene){
                return top.res;
            }
            
            for(size_t i = 0; i < startGene.size(); ++i){
                //if(startGene[i] != endGene[i]){
                    mutate('A', top.s, i, top.res, q);
                    mutate('C', top.s, i, top.res, q);
                    mutate('G', top.s, i, top.res, q);
                    mutate('T', top.s, i, top.res, q);
                  //  mutate(endGene[i], top.s, i, top.res, q);
                //}
                
            }
            q.pop();
        }   

        return -1;   
    }
};