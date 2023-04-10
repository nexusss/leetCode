class Solution {
public:
    string getHint(string secret, string guess) {
        unordered_map<char, size_t> mp;
        size_t bulls = 0, cows = 0;

        for(size_t i = 0; i < secret.size(); ++i){

            if(secret[i] == guess[i]){
                bulls++;
            }
            else{
                mp[secret[i]]++;
            }
        }

        for(size_t i = 0; i < guess.size(); ++i){
            if(secret[i] != guess[i]) {
                auto find = mp.find(guess[i]);
                if (find != mp.end()) {
                    if (find->second > 0) {
                        cows++;
                        find->second--;
                    }
                }
            }
        }

        return std::to_string(bulls) + "A" + std::to_string(cows) + "B";
    }
};