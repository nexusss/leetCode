#ifndef REVERTSTRINGS_H
#define REVERTSTRINGS_H
class Solution {
public:
    string removeStars(string s) {
        
        string result;
        result.resize(s.size());
        
        int resultIndex = 0;
        
        for(auto &c: s){
            if (c != '*'){
                result[resultIndex++] = c;
            }
            else{
                if(resultIndex - 1 >= 0)
                    resultIndex--;
            }
        }
        
        result.resize(resultIndex);
        return result;
    }
    
};
#endif // REVERTSTRINGS_H
