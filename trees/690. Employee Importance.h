/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    
    void dfs(const vector<int> &subordinates, int &res, unordered_map<int, Employee* > &mpTree){
    
        for( size_t i = 0; i < subordinates.size(); ++i){
            res += mpTree[subordinates[i]]->importance;
            dfs(mpTree[subordinates[i]]->subordinates, res, mpTree);

        }
    
    }
    
    int getImportance(vector<Employee*> employees, int id) {
        
        if (employees.empty()){
            return 0;
        }
        
        unordered_map<int, Employee* > mpTree;
        
        for (size_t i = 0; i < employees.size(); ++i){
            mpTree[employees[i]->id] = employees[i];
        
        }
        
        int res = mpTree[id]->importance;
        dfs(mpTree[id]->subordinates, res, mpTree);
        
        return res;
    }
};