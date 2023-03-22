class Solution {
public:
    
   
    vector<string> letterCombinations(string digits) {
        if (digits.empty()){
            return {};
        }
       unordered_map <char, string> mp;
        mp['2'] = {"abc"};
        mp['3'] = {"def"};
        mp['4'] = {"ghi"};
        mp['5'] = {"jkl"};
        mp['6'] = {"mno"};
        mp['7'] = {"pqrs"};
        mp['8'] = {"tuv"};
        mp['9'] = {"wxyz"};
        
        vector <string> result = {""}; 
        
        for (auto digit: digits){
            vector <string> tmp;
            for (auto lettersCombi: mp[digit]){
                
                for(auto &res: result){
                    tmp.push_back(res + lettersCombi);
                }
            }
            swap(result, tmp);
        }
        
        
        return result;
        
                
    }
};