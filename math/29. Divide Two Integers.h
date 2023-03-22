class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }
        int sign = 1;
        int64_t mdividend = abs(dividend);
        int64_t mdivisor = abs(divisor);
        if (divisor < 0 or dividend < 0){
            if (dividend > 0 or divisor > 0){
                sign = -1;
            }
        }
        
        int64_t res = 0;
        while (mdivisor <= mdividend){
            auto tmpDivisor = mdivisor;

            int k = 0;
            while (tmpDivisor * 2 <= mdividend){
                tmpDivisor <<= 1;
                ++k;
            }

            res += pow(2, k);
            
            mdividend -= tmpDivisor;
        }
        
        return res * sign;
        
        //10 = 3 * 1 + 3 * 2
        //16 = 3 * 2 * 2 + 3 
        
    }
};