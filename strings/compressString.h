#ifndef REVERTSTRINGS_H
#define REVERTSTRINGS_H
class Solution {
public:
    int compress(vector<char>& chars) {
       if (chars.empty()){
        return 0; 
       }
        
        char start = chars[0];
        int count = 1;
        
        string result;
        result.push_back(start);
        
        for (size_t i = 1; i < chars.size(); ++i){
            if (start == chars.at(i)){
                count++;
            }
            else{
                result += to_string(count);
                count = 1;
                start = chars.at(i);
                result.push_back(chars.at(i));
            }
        }
         result += to_string(count);
                
        cout << "result " << result << endl;
        return result.size();
    }
};
#endif // REVERTSTRINGS_H
