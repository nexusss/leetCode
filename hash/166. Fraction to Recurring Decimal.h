class Solution {
public:
    string intToStr(int64_t val){
        string res;
        if(val){
            while(val){
                
                char c = (val % 10) + '0';
                res = c + res;
                val /= 10;
            }
        }
        else{
            res = "0";
        }
        return res;
    }

    string afterPointToStr(uint64_t val, uint64_t denominator){
        unordered_map <uint64_t, size_t> mp;

        string res;

        while(val){
            
            //cout << "val " << val << endl;
            auto find = mp.find(val);
            if(find != mp.end()){
                res.insert(find->second, "(");
                res += ')';
                return res;  
            }
            //cout << val ;
            //cout << " " << val * 10 / (double)denominator << endl;
            /*if(val > numeric_limits<uint64_t>::max() / 10){
              return res;
            }*/
            char c = (val * 10 / (double)denominator) + '0';
            res += c;
            mp[val] = res.size() - 1;
            val *= 10;

            val %= denominator;
            

             
            //cout << "val2 " << val << " res " << res << " " << tmp << endl;
        }

        return res;
    }

    string fractionToDecimal(int numerator, int denominator) {
        string result;
        if(numerator == 0){
          return "0";
        }

int64_t n = numerator;
int64_t d = denominator;

//cout << n << " " << d << endl;
        if ((n < 0 and d > 0) or (n > 0 and d < 0)){
            result = "-";
        }
        if(d < 0){
              d *= -1;
            }
            if(n < 0){
              n *= -1;
            }
        auto res = n / double (d);
        //cout << res << endl;
        result += intToStr(res);
        //cout << n << " " << d << endl;
        string apts = afterPointToStr(n % d, d);
        if(!apts.empty()){
            result += "." + apts;
        }
        
        return result;
    }
};