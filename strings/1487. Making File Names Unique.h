class Solution {
public:
    vector<string> getFolderNames(vector<string>& names) {
        unordered_map<string, int> namesmp;
        vector<string> result;
        
        for(auto &name: names){
            auto find = namesmp.find(name);
            if (find != namesmp.end()){
                size_t i = find->second;
                string newname;
                auto oldfind = find;
                do{
                    
                    newname = name + "(" + to_string(i) + ")";
                    find = namesmp.find(newname);
                    ++i;
                }while (find != namesmp.end());
                oldfind->second = i - 1;
                namesmp.emplace(newname, 1);
                result.emplace_back(move(newname));
            }
            else{
                namesmp.emplace(name, 1);
                result.emplace_back(name);
            }
        }
        return result;
    }
};