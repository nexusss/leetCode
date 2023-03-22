#ifndef STRINGATOI_H
#define STRINGATOI_H
class Solution {
public:
    
    //"/a//b////c/d//././/.."

    string simplifyPath(string path) {
        stack <string> dirName;
        
        size_t iter = 1;
        while(iter < path.size()){
            auto nextiter = path.find('/', iter);
            if (nextiter == string::npos){
                nextiter = path.size();
            }
            string insert = path.substr(iter, nextiter - iter);

            
            iter = nextiter + 1;
            
            if (insert.empty() || insert == "."){
                continue;
            }
            
            if (insert == ".."){
                if(!dirName.empty())
                    dirName.pop();
            }
            else{
                dirName.emplace(insert);
            }
        }
        
        string result = dirName.empty() ? "/" : "";
        while(!dirName.empty()){
            result = "/" + dirName.top() + result;
            dirName.pop();
        }
        return result;
    }
};
#endif // STRINGATOI_H
