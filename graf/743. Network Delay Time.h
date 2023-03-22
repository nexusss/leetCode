class Solution {
public:
    //deikstra
	class Solution {
public:
    
        void dfs(const vector <vector<pair<int, int>>> &adj,const pair<int, int> &v, int parent, int prevWeight, vector<int> &weight){
        if (weight.at(v.first) < prevWeight + v.second){
            return;
        }
   
        priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int,int>>> pq;
        
        for(auto &u: adj.at(v.first)){
            if (u.first != parent && weight.at(u.first) > weight.at(v.first) + u.second){
                weight.at(u.first) = weight.at(v.first) + u.second;
                //cout << "u first " << u.first << " " << weight.at(u.first) << " " << prevWeight << endl;
                pq.emplace(u);
            }
        }
        
        //cout << v.first << " "<< pq.size() << endl;   
            
        while(!pq.empty()){   
            //cout << "pq " << pq.top().first << " " << pq.top().second << endl;
            
            dfs(adj, pq.top(), v.first, weight.at(v.first), weight);  
            pq.pop();
        }
    }
    
    
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        vector<int> weight(n + 1, numeric_limits<int>::max());
        
        vector <vector<pair<int, int>>> adj(n + 1);
        
        for(auto &time: times){
            adj.at(time.at(0)).push_back({time.at(1), time.at(2)});
            
        }
        weight.at(k) = 0;
        
        priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int,int>>> pq;
        
        for(auto &v: adj.at(k)){
            weight.at(v.first) = v.second;
            pq.emplace(v);
        }

        int prevWeight = 0;
        
        while(!pq.empty()){
            dfs(adj, pq.top(), k, 0, weight);
            pq.pop();
        }
        
        int ans = 0;
        
        for(int i = 1; i <= n; ++i){
                        
            if (weight.at(i) == numeric_limits<int>::max()){
                return -1;
            }
            //cout << i  << " " << weight.at(i) << endl;
            ans = max(ans, weight.at(i));
        }
        
        return ans;
    }
};

//worth	
	
    void dfs(const vector<vector<pair<int, int> >> &edges, pair<int, int> v, int p, int weight, vector<int> &visited){
        
        //cout << "v " << v.first << " w " << weight << endl;
        auto newWeight = v.second + weight;
        if (visited[v.first] < newWeight )
            return;
        
        visited[v.first] = newWeight;
        
        for (auto& edge: edges[v.first]){
            if (edge.first == p) continue;
            //cout << "from " << v.first << " to ";
            dfs(edges, edge, v.first, newWeight, visited);
        }
    }
    
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        vector<vector<pair<int, int> >> edges(n + 1);
        
        vector<int> visited(n + 1, numeric_limits<int>::max());
        
        for(auto t: times){
            edges[t[0]].emplace_back(t[1], t[2]);
        }
        
        
        int minres = 0;
        
        for (auto &edge: edges[k]){
                //cout << "from " << k << " to ";
                //dfs(edges, edge, k, 0, visited);
            
                
        }
        
        for(int i = 1; i < visited.size(); ++i){
            //cout << "i " << i << " " << visited[i] << endl;
            if (i == k) continue;
            if (visited[i] == numeric_limits<int>::max()){
                return -1;
            }
            
            minres = max(minres, visited[i]);
        }
        
        return minres;
    }
};