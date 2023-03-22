class Solution {
public:
    string convert(string s, int numRows) {
        vector <string> zigzagStrings(numRows);
        
        bool directDown = true;
        
        for (size_t i = 0; i < s.size();){
            
            if (directDown){
                for (size_t j = 0; j < numRows && i < s.size(); ++j, ++i){
                   zigzagStrings[j] += s[i];
                }
                directDown = false;
            }
            else{
                for (int j = numRows - 2; j > 0 && i < s.size(); --j, ++i){
                   zigzagStrings[j] += s[i];
                }
                directDown = true;
            }
            
        }
        
        string res;
        
        for(auto &str: zigzagStrings){
            //cout << str << endl;
            res += str;
        }
        
        return res;
    }
};