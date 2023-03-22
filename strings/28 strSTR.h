#ifndef STRINGATOI_H
#define STRINGATOI_H
class Solution {
public:
    int strStr(string haystack, string needle) {
        if (haystack.size() < needle.size()){
            return -1;
        }

        auto hashNeedle = hash<string>()(needle);

        for(size_t i = 0; i + needle.size() - 1 < haystack.size(); ++i){
            auto hashFind = hash<string>()(string(haystack.begin() + i, haystack.begin() + i + needle.size()));
            if (hashFind == hashNeedle){
                return i;
            }
        }

        return -1;
    }
};
#endif // STRINGATOI_H
