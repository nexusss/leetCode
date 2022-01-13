#ifndef STRINGATOI_H
#define STRINGATOI_H
class SolutionAtoi {
public:
    int myAtoi(string s) {
        if (s.empty())
            return 0;

        int i = 0;
        int result = 0;
        char ch = s.at(i);
        bool negative = false;

        while(ch == ' ' or ch == '-' or ch == '+'){
            ++i;
            if(ch == '-'){
                negative = true;
                break;
            }
            if(ch == '+')
                break;


            if (i == s.size())
                break;
            ch = s.at(i);
        }

        if (i < s.size()){
            ch = s.at(i);

            while ((ch - '0' >= 0 && ch - '9' < 9)){

                    if (negative == false){
                        if (result < (INT_MAX - (ch - '0') ) / 10.0)
                            result = result * 10 + (ch - '0');
                        else
                            return INT_MAX;
                    }
                    else{
                        int nres = (ch - '0') * -1;
                        if (result > (INT_MIN - nres ) / 10.0 )
                            result = result * 10 + nres;
                        else
                            return INT_MIN;
                    }


                ++i;
                if (i == s.size())
                    break;
                ch = s.at(i);
            }
        }
        return result;
    }
};
#endif // STRINGATOI_H
