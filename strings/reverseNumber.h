#ifndef REVERSENUMBER_H
#define REVERSENUMBER_H
class SolutionReverseNumer {
public:
    int reverse(int x) {
        int rev = 0;
        while (x != 0){
            auto pop = x % 10;
            x /= 10;
            rev = rev * 10 + pop;
        }

        return rev;
    }
};
#endif // REVERSENUMBER_H
