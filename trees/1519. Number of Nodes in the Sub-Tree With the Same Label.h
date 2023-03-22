#ifndef MAXDEPTH_H
#define MAXDEPTH_H
/**
 Input: n = 7, edges = [[0,1],[0,2],[1,4],[1,5],[2,3],[2,6]], labels = "abaedcd"
Output: [2,1,1,1,1,1,1]
Explanation: Node 0 has label 'a' and its sub-tree has node 2 with label 'a' as well, thus the answer is 2. Notice that any node is part of its sub-tree.
Node 1 has a label 'b'. The sub-tree of node 1 contains nodes 1,4 and 5, as nodes 4 and 5 have different labels than node 1, the answer is just 1 (the node itself).
 */
class Solution {
public:
    
    void dfs(vector <vector<int>> &list, int node, int arrival,const string &labels, array<int, 27> &lettersArr, vector<int> &result)
    {

        // Printing traversed node
        //cout << node << " " << labels[node] << '\n';
    array<int, 27> newlettersArr = {0};
        // Traversing adjacent edges
        for (int i = 0; i < list[node].size(); i++) {
            //cout << list[node][i] << " parent " << arrival << endl;
            // Not traversing the parent node
            if (list[node][i] != arrival){
                
                //cout << "newlettersArr[labels[node] - 'a'] " << newlettersArr[labels[node] - 'a'] << endl;
                dfs(list, list[node][i], node, labels, newlettersArr, result);

            }
        }
        
                        
                newlettersArr[labels[node] - 'a'] += 1;
                for(size_t i = 0; i < 27; ++i){
                    lettersArr[i] += newlettersArr[i];
                }
                
        
        result[node] = newlettersArr[labels[node] - 'a'];
        
    }
    
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector <vector<int>> graf(n);
        
        vector<int> result(n, 1);
        
        array<int, 27> lettersArr = {0};
        
        for(auto &edge: edges){
            graf[edge[0]].emplace_back(edge[1]);
            graf[edge[1]].emplace_back(edge[0]);
            
        }
        
       dfs(graf,0,0, labels, lettersArr, result);
        
        return result;
    }
};
#endif // MAXDEPTH_H
