class Solution {
public:
    int titleToNumber(string columnTitle) {
        int result = 0;
        //reverse(columnTitle.begin(), columnTitle.end());
        
        for (auto col: columnTitle){
            
            result *= 26;
            
            result += (col - 'A') + 1;
        }
        
        return result;
    }
};