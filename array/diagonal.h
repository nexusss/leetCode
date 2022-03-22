#ifndef SINGLENUMBER_H
#define SINGLENUMBER_H
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        
        vector <int> result;
        if (mat.size() == 0)
            return result;
        if(mat.at(0).size() == 0)
            return mat.at(0);
        
        size_t i = 0, k = 0, counter = 0;
        bool direction = true;
        while ( counter < mat.size() * mat.at(0).size()){
        //up
            if(direction){
                do  {
                    cout << "up" << "i" << i << "k" << k << endl;
                    result.push_back(mat.at(i).at(k));
                    counter++;
                    if (k < mat.at(0).size() - 1)
                        ++k;
                    else{
                        ++i;
                        break;
                    }

                    if (i != 0)
                        --i;
                    else
                        break;

                    

                 }while (true);
                direction = !direction;
            }
            else{
            //down
                do {
                    cout << "down" << "i" << i << "k " << k << endl;
                    result.push_back(mat.at(i).at(k));
                    counter++;
                    if(i < mat.size() - 1)
                        ++i;
                    else{
                        ++k;
                        break;
                    }

                    if (k != 0)
                        --k;
                    else
                        break;
                    
                    

                }while(true);
                direction = !direction;
            }
        }
        
        return result;
    }
};
#endif // SINGLENUMBER_H
