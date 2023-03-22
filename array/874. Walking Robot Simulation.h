class Solution {
    
    array <int, 4> directX = {0, 1, 0, -1};
    array <int, 4> directY = {1, 0, -1, 0};
    
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int x = 0;
        int y = 0;
        int direct = 0;
        
        
        int maxDistance = 0;
        
        unordered_set<string> ob;
        
        for(auto obs: obstacles){
            ob.insert(to_string(obs[0])+":"+to_string(obs[1]));
        }
        
        
        for (auto command: commands){
            
            if (command == -1){
                direct++;
                if (direct == 4){
                    direct = 0;
                }
            }
            else if(command == -2){
                direct--;
                if (direct == -1){
                    direct = 3;
                }
            }
            else{
                for (int i = 0; i < command; ++i){
                    auto nx = x + directX[direct];
                    auto ny = y + directY[direct];
                    if (ob.find(to_string(nx)+":"+to_string(ny)) == ob.end()){
                        x = nx;
                        y = ny;
                        maxDistance = max(maxDistance, x * x + y * y);
                    }
                }
                
            }
        }
        
        return maxDistance;
    }
};