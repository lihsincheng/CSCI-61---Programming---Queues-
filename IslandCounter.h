#ifndef ISLANDCOUNTER_H
#define ISLANDCOUNTER_H


#include <vector>

class IslandCounter {
public:
    int countIslands(std::vector<std::vector<int>>& grid);
    
private:
    void dfs(std::vector<std::vector<int>>& grid, 
             std::vector<std::vector<bool>>& visited, 
             int i, int j, int rows, int cols);
};

#endif