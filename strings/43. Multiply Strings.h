class Solution {
public:
    
    string mul1num(const string& num1, int num2, int zeros){
        string result(zeros, '0');
        
        int caryFlag = 0;
        
        for(int i = 0; i < num1.size(); ++i){
            int a = num1[i] - '0';
            
            int res = a * num2;
            
            if (caryFlag){
                res += caryFlag;
            }
            
            
            if (res > 9){
                caryFlag = res / 10;
                res -= caryFlag * 10;
            }
            else{
                caryFlag = 0;
            }
            result += to_string(res);
        }
        
        if (caryFlag){
            result += to_string(caryFlag);
        }
        
        return result;
    }
    
    string sum(const string &num1, const string &num2){
        int maxSize = max(num1.size(), num2.size());
        
        string result;
        int caryFlag = 0;
        
        for(int i = 0; i < maxSize; ++i){
            int a = i < num1.size() ? num1[i] - '0' : 0;
            int b = i < num2.size() ? num2[i] - '0' : 0;
            int res = a + b;
            
            if (caryFlag){
                res += caryFlag;
            }
            
            
            if (res > 9){
                caryFlag = res / 10;
                res -= caryFlag * 10;
            }
            else{
                caryFlag = 0;
            }
            result += to_string(res);
        }
        
        if (caryFlag){
            result += to_string(caryFlag);
        }
        return result;
    }
    
    string multiply(string num1, string num2) {
        if (num1 == "0" or num2 == "0"){
            return "0";
        }
        
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        
        int maxSize = max(num1.size(), num2.size());
        
        string result;
        
        for(int i = 0; i < num2.size(); ++i){
            auto tmp = mul1num(num1, num2[i] - '0', i);
          
            result = sum(tmp, result);
            
        }
        
        reverse(result.begin(), result.end());
                
        return result;
    }
};