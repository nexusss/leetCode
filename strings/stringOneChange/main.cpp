#include <iostream>

using namespace std;

bool equal(const string &str1,const string &str2){
    auto minSize = min(str1.size(), str2.size());
    auto maxSize = max(str1.size(), str2.size());
    if (maxSize - minSize > 1){
        return false;
    }


    int maxChanges = maxSize != minSize ? 0: 1;
    for(size_t i = 0; i < minSize; ++i){
        if (str1[i] != str2[i]){
            if (maxChanges == 0){
                return false;
            }
            else{
                maxChanges--;
            }
        }
    }

    return true;
}

int main()
{
    string str1 = "abcd";
    string str2 = "abcdaa";



    cout << "equal " << equal(str1, str2) << endl;
    return 0;
}
