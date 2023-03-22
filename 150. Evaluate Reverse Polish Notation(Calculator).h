#ifndef SINGLENUMBER_H
#define SINGLENUMBER_H
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        
        for(auto &t: tokens){
            if (t == "+" || t == "-" || t == "/" || t == "*"){
                int a = 0, b = 0;
                if (!st.empty()){
                    a = st.top();
                    st.pop();
                    if (!st.empty()){
                        b = st.top();
                        st.pop();
                        if (t == "+"){
                            st.push(a + b);
                        }
                        else if ( t == "-"){
                            st.push(b - a);
                        }
                        else if (t == "/"){
                            st.push(b / a);
                        }
                        else if(t == "*"){
                            st.push(a * b);
                        }
                    }
                }
                
            }
            
            else{
                st.push(stoi(t));
            }
        }
        return st.empty() ? 0 : st.top();
    }
};s

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
 #endif // SINGLENUMBER_H
