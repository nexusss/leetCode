#ifndef FINDTWOSUM_H
#define FINDTWOSUM_H
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

std::vector <int> v = {17, 2 , 5 , 8, 13 , 12, 1 , 6, 7, 18};
    size_t l = 0;
    size_t r = 0;
    uint64_t findSum = 0;
    uint64_t sum = 14;

    for(;r < v.size(); ++r){
        findSum += v[r];
        if(findSum == sum){
            std::cout << v[l] << " " << v[r] << std::endl;
            break;
        }
        while (findSum > sum){
            findSum -= v[l];
            ++l;
        }
    }

#endif // FINDTWOSUM_H
