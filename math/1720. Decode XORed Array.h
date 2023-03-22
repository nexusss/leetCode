class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        if(encoded.empty()){
            return {first};
        }
        
        vector<int> result (encoded.size() + 1);
        result[0] = first;
        
        for(int i = 1; i < result.size(); ++i){
            result[i] = result[i - 1] ^ encoded[i - 1];
        }
        
        return result;
    }
};