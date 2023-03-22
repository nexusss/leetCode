class Solution {
public:

    void backTracking(vector<string> &result, string str, int openN, int closeN, int n){
        
        if(closeN == n){
            result.push_back(str);
            return;
        }

        if(openN < n){
            backTracking(result, str + "(", openN + 1, closeN , n);
        }

        if (openN > closeN){
            backTracking(result, str + ")", openN , closeN + 1, n);
        }

    }

    vector<string> generateParenthesis(int n) {
        vector<string> result;

        string tmp;
        
        backTracking(result, tmp, 0, 0, n);

        return result;
        
    }
};