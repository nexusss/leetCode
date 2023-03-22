class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if (amount == 0){
            return 0;
        }
        
        if (coins.size() == 1){
            if ( amount % coins[0] == 0){
                return amount / coins[0];
            }
            return -1;
        }
        
        
        
        vector<int> am(amount + 1, numeric_limits<int>::max());
        am[0] = 0;
        
        vector<int> coinscounter(coins.size());
        
        for(int i = 1; i < am.size(); ++i){
            for(auto coin: coins){
                
                //cout << i << " " << i - coin << endl;
                if(i - coin >= 0 and am[i - coin] < numeric_limits<int>::max()){
                    am[i] = min(am[i], am[i - coin] + 1);
                }
                
            }
            
        }
            
        return am.back() < numeric_limits<int>::max() ? am.back() : -1;
    }
};