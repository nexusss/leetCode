class Solution {
public:
    void dfs(vector <vector <int>> &graf, int nodeIndex, vector<bool> &visited,long long &counter){
        
        visited[nodeIndex] = true;
        counter++;
        for(auto &nodes: graf[nodeIndex]){
            if (visited[nodes] == false){
                //cout << "nodes " << nodes << " " << counter << endl;
                dfs(graf, nodes, visited, counter);
                
                //cout << "nodes " << nodes << " " << counter << endl;
            }
        }
        
        
        
        
    }
    
    long long countPairs(int n, vector<vector<int>>& edges) {
        if(edges.empty()){
            return (pow(n, 2) - n) / 2;
        }
        
        vector <vector <int>> graf(n);
        
        for (auto &edge: edges){
            graf[edge[0]].emplace_back(edge[1]);
            graf[edge[1]].emplace_back(edge[0]);
        }
        
        long long res = 0;
        vector<bool> visited(n);
        
        for (size_t i = 0; i < n; ++i){
            if (visited[i] == false){
                //cout << "nodesIndex " << i << " " << endl;
                long long count = 0;
                dfs(graf, i, visited, count);
                
                long long unreachable=n-count;

                long long z=count*unreachable;
                cout << "i " << i << " count " << count << " z " << z << " un " << unreachable << endl;
                res+=(z);
            }
        }
                
        
        return res / 2 ;
    }
};