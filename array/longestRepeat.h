#ifndef SINGLENUMBER_H
#define SINGLENUMBER_H
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

class Solution {
    static const size_t arrSize = 128;
    int arr[arrSize] = {-1};
public:
    
    void isRepeat(char c, size_t pos,int &result,int &maxResult, int &lastNotRepeatPos){
        size_t index = c;
        

        if (arr[index] >= 0){
            maxResult = max(result, maxResult);
            lastNotRepeatPos = max (arr[index],lastNotRepeatPos) ;
            //result = arr[index];
            //cout << "result   " << result << " " << maxResult << " i " << pos << "\r\n";
            //cout << "result 2 " << result << "\r\n";
            //clear();
            arr[index] = pos;
        }
        else{
            //result = pos - arr[index];cabcbb
            arr[index] = pos;
            
        }
        result = pos - lastNotRepeatPos;
    }
    
    
    void clear(){
        for(int i = 0; i < arrSize; i++)
            arr[i] = -1;
    }
    int lengthOfLongestSubstring(string s) {
        int result = 0;
        int maxResult = 0;
        int i = 0;
        int lastNotRepeatPos = -1;
        clear();
        for(auto c: s){
            
            isRepeat(c, i, result, maxResult, lastNotRepeatPos);
            ++i;A
        }
        maxResult = max(result, maxResult);
        return maxResult;
    }
};
#endif // SINGLENUMBER_H
