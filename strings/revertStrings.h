#ifndef REVERTSTRINGS_H
#define REVERTSTRINGS_H
class SolutionReversS {
public:
    void reverseString(vector<char>& s) {
        for(int i = 0, k = s.size() - 1; i < k; ++i, --k){
             swap(s[i],s[k]);
        }
    }
};
#endif // REVERTSTRINGS_H
