class Solution {
public:
    
    string getVal(const string &s, size_t &i){
        int start = i;
        while( i < s.size() && s.at(i) >= '0' && s.at(i) <= '9'){
            ++i;
        }
        
        return s.substr(start, i - start );
    }
    
    vector<string> convertToPostfix(const string &str){
        vector<string> nums;
        stack<char> operators;
        
        for (size_t i = 0; i < str.size(); ++i){
            auto letter = str.at(i);
            if (letter == ' '){
                continue;
            }
            if(letter >= '0' && letter <= '9'){
                auto s = getVal(str, i);
                nums.emplace_back(s);
                --i;
            }
            else{
                if (letter == '+' || letter == '-'){
                    while (!operators.empty()){
                        string s;
                        s = (operators.top());
                        nums.push_back(s);
                        operators.pop();
                    }
                    operators.emplace(letter);
                }
                else if(letter == '*' || letter == '/'){
                    if (!operators.empty() && (operators.top() == '*' || operators.top() == '/')){
                        string s;
                        s = (operators.top());
                        nums.push_back(s);
                        operators.pop();
                    }
                    operators.emplace(letter);
                }
            }
        }
        
        while (!operators.empty()){
            string s;
            s = (operators.top());
            nums.push_back(s);
            operators.pop();
        }
        return nums;
    }
    
    int calculate(string s) {
        
        auto postfix = convertToPostfix(s);
        for(auto str: postfix){
            cout << str << " ";
        }
        cout << endl;
        stack<int> nums;
        
        for(auto str: postfix){
            if (str == "+"){
                auto num1 = nums.top();
                nums.pop();
                auto num2 = nums.top();
                nums.pop();
                nums.emplace(num1 + num2);
            }
            else if(str == "-"){
                auto num1 = nums.top();
                nums.pop();
                auto num2 = nums.top();
                nums.pop();
                nums.emplace(num2 - num1);
            }
            else if(str == "*"){
                auto num1 = nums.top();
                nums.pop();
                auto num2 = nums.top();
                nums.pop();
                nums.emplace(num1 * num2);
            }
            else if(str == "/"){
                auto num1 = nums.top();
                nums.pop();
                auto num2 = nums.top();
                nums.pop();
                nums.emplace(num2 / num1);
            }
            else{
                nums.emplace(stoi(str));
                
            }
        }
        return nums.top();
    }
};