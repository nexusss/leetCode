class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0){
            return 1;
        }
        if (x == 1){
            return x;
            
        }
        double ans = 1;
        	uint64_t p;
        	if (n < 0) {
        		p = (uint64_t)((int64_t)n * -1);
        		x = 1 / x;
        	} else {
        		p = (uint64_t)n;
        	}
    		while (p) {
    			if (p & 1)
    				ans *= x;
    			x *= x;
    			p >>= 1;
    		}
        return ans;
    }
};