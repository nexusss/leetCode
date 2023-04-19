class Solution {
public:
    bool circularArrayLoop(vector<int>& nums) {

        vector<bool> visited(nums.size(), false);
//[1,0,0,0,0,0]
//[1,0,0,0,0,2]
//[1,1,0,0,0,2]
//0 -> 2 -> 3 -> 1 -> 0
//4 -> 2 -> 3 -> 1 -> 0 -> 2
        for(int i = 0; i < nums.size(); ++i){

            const bool positiveDirection = (nums[i] > 0);
            if(visited[i] == 0){

                unordered_set<int> edges;
                auto tmpi = i;
                while(true) {

                    if(edges.count(tmpi)){
                        return true;
                    }
                    else {
                        if(visited[tmpi] or positiveDirection != nums[tmpi] > 0){
                            break;
                        }
                        edges.insert(tmpi);

                        visited[tmpi] = true;
                        auto nextI = nums[tmpi] + tmpi;

                        while (nextI < 0) {
                            nextI += nums.size();
                        } 
                        while (nextI >= nums.size()) {
                            nextI -= nums.size();
                        }
                        if (tmpi != nextI) {
                            tmpi = (nextI);
                        } else {
                            break;
                        }
                    }
                }
            }
        }

        return false;
    }
};
