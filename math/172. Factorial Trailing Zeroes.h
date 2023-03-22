class Solution {
public:
    int trailingZeroes(int n) {
        if (n < 5){
            return 0;
        }
        int k = 1;
        int pow5 = pow(5,k);
        int res = 0;
        while(pow5 <= n){
            
            res += n / pow5;
            ++k;
            pow5 = pow(5, k);
        }
        return res;
    }
};