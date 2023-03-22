class Solution {
public:
    vector<pair<int, string>> nums ={{1000000000, "Billion"}, {1000000, "Million"}, 
    {1000, "Thousand"}, {100, "Hundred"}, {90, "Ninety"}, {80, "Eighty"}, {70, "Seventy"},
    {60, "Sixty"}, {50, "Fifty"}, {40, "Forty"}, {30, "Thirty"}, {20, "Twenty"}, {19, "Nineteen"}, 
    {18, "Eighteen"}, {17, "Seventeen"}, {16, "Sixteen"}, {15, "Fifteen"}, {14, "Fourteen"}, 
    {13, "Thirteen"}, {12, "Twelve"}, {11, "Eleven"}, {10, "Ten"}, {9, "Nine"}, {8, "Eight"}, 
    {7, "Seven"}, {6, "Six"}, {5, "Five"}, {4, "Four"}, {3, "Three"}, {2, "Two"}, {1, "One"}};
    
    string numberToWords(int num) {
        if(num == 0)   return "Zero";
        
        for(auto it: nums)
            if(num >= it.first)
                return (num >= 100 ? numberToWords(num/it.first)+" " : "") + it.second + (num%it.first == 0 ? "" : " "+numberToWords(num%it.first));
    
        return "";
    }
};
// my
class Solution {
    
    vector <int> numbers = {1,2,3,4,5,6,7,8,9,10,11,12,13,14};
    vector <string> numbersText = {
                                  "One",
                                  "Two",
                                  "Three",
                                  "Four",
                                  "Five",
                                  "Six",
                                  "Seven",
                                  "Eight",
                                  "Nine",
                                  "Ten",
                                  "Eleven",
                                  "Twelve",
                                  "Thirteen",
                                  "Fourteen"};
        vector <string> numbersTextDec = {
                                  "For",
                                  "Fif",
                                  "Six",
                                  "Seven",
                                  "Eigh",
                                  "Nine",
                                  };
    
public:
    
    string lessHundred(int num){
        if (num == 0 or num >= 100){
            return "";
        }
        
        if (num <= 14){
            return numbersText[num - 1];
        }
        else if (num > 14 and num < 20 ){
            int secondnumber = num - 10;
            return numbersTextDec[secondnumber - 4] + "teen";
        }
        else{
            int firstnumber = num / 10;
            int secondnumber = num % 10;
            
            string res;
                
            if (firstnumber == 2){
                res = "Twenty";
            }
            
            else if (firstnumber == 3){
                res = "Thirty";
            }
            else{
                res = numbersTextDec[firstnumber - 4] + "ty";
            }
            
            if (secondnumber != 0){
                res += res.empty() ? "" : " ";
                res += numbersText[secondnumber - 1];
            }
            
            return  res;
        }
                
    }
    
    string lessThousend(int num){
        string res;
        
        int hundreds = num / 100;
        if (hundreds > 0){
            res = lessHundred(hundreds) + " Hundred";
        }
        
        int remainder = num % 100;
        if (remainder > 0){
            res += res.empty() ? "" : " ";
            res += lessHundred(remainder);
        }
        return res;
        
    }
    
    string numberToWords(int num) {
        if (num == 0){
            return "Zero";
        }
        
        string res;
        
        while (num > 0){
            res += res.empty() ? "" : " ";
            if (num >= pow(10, 9)){
                int tmp = num / pow(10,9);
                res += lessThousend(tmp) + " Billion";
                num -= tmp * pow(10, 9);
            }
            else if (num >= pow(10, 6)){
                int tmp = num / pow(10,6);
                res += lessThousend(tmp) + " Million";
                num -= tmp * pow(10, 6);
            }
            else if (num >= pow(10, 3)){
                int tmp = num / pow(10,3);
                res += lessThousend(tmp) + " Thousand";
                num -= tmp * pow(10, 3);
            }
            else{
                res += lessThousend(num);
                num = 0;
            }
        }
        //for (int i = 1; i < 99; ++i){
        //    cout << "i " << i << " " << lessHundred(i) << endl;
        //}
        //cout << res << endl;
        
        return res;
    }
};