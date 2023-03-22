#ifndef SINGLENUMBER_H
#define SINGLENUMBER_H
#include <vector>
#include <algorithm>
#include <set>

using namespace std;
class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        
        unordered_map <int, array<int,10>> um;
        
        for (int i = 0; i < reservedSeats.size(); ++i){
            um[reservedSeats[i][0]][reservedSeats[i][1] - 1] = 1; 
        }
        
        const int maxLength = 4;
        
        int result = (n - um.size()) * 2; //если есть свободные ряды, то они не попадут хэш таблицу. Это вычисление количества свободных мест в пустующих рядвх
        for(auto &seat: um){
            auto &arr = seat.second;
            int curLen = 0;
            //cout << seat.first;
            for(size_t i = 0; i < arr.size();++i){
                //cout << "arr " << i + 1<< " " << arr[i];
                if (arr[i] == 0){
                    curLen++;
                }
                else{
                    curLen = 0;
                }
                
                if(i == 2 || i == 6 ){
                    if(curLen < 2){
                        curLen = 0;
                    }
                    else if (curLen == 3){
                        curLen--;
                    }
                }
                
                //cout << " " << curLen << " " ;
                if (curLen == maxLength){
                    result++;
                    curLen = 0;
                }
            }
            cout << endl;
        }
        return result;
    }
};
};#endif // SINGLENUMBER_H
