#ifndef PLUSONE_H
#define PLUSONE_H

#include <vector>

using namespace std;

class SolutionPO {
public:
    vector<int> plusOne(vector<int>& digits) {
            const auto size = digits.size();
            if (size > 0){
                if(digits.at(size - 1) < 9){
                    ++digits[size-1];
                    return digits;
                }
                else{
                    int i = size - 1;
                    while (digits.at(i) == 9){
                        digits[i] = 0;
                        --i;
                        if (i < 0){
                            digits.push_back(0);
                            i = 0;
                            break;
                        }
                    }

                    digits[i]++;
                }
            }
            return digits;
        }
};
#endif // PLUSONE_H
