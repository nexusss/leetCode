#ifndef SINGLENUMBER_H
#define SINGLENUMBER_H
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

class Solution {
public:
    int countPrimes(int n) {
        vector<bool> arr (n+1, true);
        arr.resize(n + 1);
        arr[0] = false;
        arr[1] = false;
        
        for (int i = 2; i * i <= n; ++i){
            if (arr[i]){
                cout << "i " << i << endl;
                for (int j = i * i; j  <= n; j += i){
                    cout << "j " << j;
                    arr[j] = false;

                }
                cout << endl;
            }
            
        }
        
        int res = 0;
        for (auto num: arr){
            if (num){
                res++;
            }
        
        }
        
        return res;
    }
};
 #endif // SINGLENUMBER_H
