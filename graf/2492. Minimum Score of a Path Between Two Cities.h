class Solution {
    vector<bool> visited;
    vector<vector<pair<int, int>>> egdesList;
    
public:
    
    void dfs(int point,const int endPoint, int& minVal){

        if (visited[point]){
            return;
        }
        
        visited[point] = true;
            
        if (point == endPoint){
            return;
        }
        
        for(auto edg: egdesList[point]){
            minVal = min(edg.second, minVal);
            
            dfs(edg.first, endPoint, minVal);
        }
        
    }
    
    int minScore(int n, vector<vector<int>>& roads) {
        if ( n < 1){
            return 0;
        }
        
        visited.resize(n + 1, false);
        egdesList.resize(n + 1);
        int minVal = numeric_limits<int>::max();
        
        for(auto road: roads){
            egdesList[road[0]].emplace_back(road[1], road[2]);
            egdesList[road[1]].emplace_back(road[0], road[2]);
            
        }
        
        dfs(1, n, minVal);
        
        return minVal;
        
    }
};