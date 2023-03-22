class Solution {
    vector<int> tin; //время входа в вершину
    vector<int> fup; //номер минимального предка, которого мы можем достичь
    //получается, что если минимальная вершина у потомка, которую мы можем достичь меньше, чем та на которой мы стоим то это цикл,
    //если больше, то это мост
public:
    void dfs(const vector <vector<int> > &edges, int v, int p, vector<bool> &visited, int time, vector<vector<int>>& res){
        
        visited[v] = true;
        
        tin[v] = time;
        fup[v] = time;
        
        time++;
        
        for(auto edge: edges[v]){
            if (edge == p) continue;
            
            if(!visited[edge]){
                dfs(edges, edge, v, visited, time, res);
                
                fup[v]=min(fup[v],fup[edge]);
                if(tin[v] < fup[edge])//если минимаьная вершина потомка(fup) больше, чем номер текушей вершины, то это мост
                    res.push_back({v,edge});
            }
            else{
                fup[v]=min(fup[v],tin[edge]);
            }
        }
        
    }
    
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        
        vector <vector<int> > edges(n);
        
        vector<bool> visited(n);
        
        tin.resize(n);
        fup.resize(n);
        vector<vector<int>> res;
            
        for(const auto &con: connections){
            edges[con[0]].emplace_back(con[1]);
            edges[con[1]].emplace_back(con[0]);
        }
        
        dfs(edges, 0, -1, visited, 0, res);
        
        return res;
        
    }
};