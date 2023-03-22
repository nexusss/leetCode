#ifndef MAXDEPTH_H
#define MAXDEPTH_H

class Solution {

public:
    bool isValidPath(int x, int y, vector<vector<int>>& grid){
        return (x >= 0 && y >= 0 && x < grid.size() && y < grid[0].size());
    }
    
    
    void dfs(int x, int y, vector<vector<int>>& grid, vector<vector<bool>>& visited){
        if(visited[x][y])
            return;
        
        visited[x][y] = true;
        
        int left = 0, right = 0, up = 0, down = 0;
        
        switch(grid[x][y]){
            case 1:{
                left = 1;
                right = 1;
                break;
            }
            case 2:{
                up = 1;
                down = 1;
                break;
            }
            case 3:{
                left = 1;
                down = 1;
                break;
            }
            case 4:{
                right = 1;
                down = 1;
                break;
            }
            case 5:{
                left = 1;
                up = 1;
                break;
            }
            case 6:{
                left = 1;
                right = 1;
                break;
            }
        }
        
        if(left){
            int newY = y - 1;
            if (isValidPath(x, newY, grid) && (grid[x][newY] == 1 || grid[x][newY] == 4 || grid[x][newY] == 6))
                dfs(x,newY,grid,visited);
        
        }
        
        if(right){
            int newY = y + 1;
            if (isValidPath(x, newY, grid) && (grid[x][newY] == 1 || grid[x][newY] == 3 || grid[x][newY] == 5))
                dfs(x,newY,grid,visited);
        
        }
        
        if(up){
            int newX = x - 1;
            if (isValidPath(newX, y, grid) && (grid[newX][y] == 2 || grid[newX][y] == 4 || grid[newX][y] == 3))
                dfs(newX,y,grid,visited);
        
        }
        
        if(down){
            int newX = x + 1;
            if (isValidPath(newX, y, grid) && (grid[newX][y] == 2 || grid[newX][y] == 5 || grid[newX][y] == 6))
                dfs(newX,y,grid,visited);
        
        }
    }
    
    bool hasValidPath(vector<vector<int>>& grid) {
        if(grid.size() == 0){
            return false;
        }
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        dfs(0,0, grid, visited);
        return visited[grid.size() - 1][grid[0].size() - 1];
        
    }
};
#endif // MAXDEPTH_H
