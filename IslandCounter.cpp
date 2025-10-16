#include "IslandCounter.h"
#include <vector>
#include <iostream>
using namespace std;

// 1 = land, 0 = water, island is a group of connected 1s
// We want to count how many islands exist

int IslandCounter::countIslands(vector<vector<int>>& grid) {
    // If the grid is empty, there are no islands
    if (grid.empty() || grid[0].empty()) {
        return 0;
    }
    
    int rows = grid.size();
    int cols = grid[0].size();
    int islandCount = 0;
    
    // Keep track of which cells we've already checked
    // This prevents counting the same island multiple times
    vector<vector<bool>> visited(rows, vector<bool>(cols, false));
    
    // Look at every cell in the grid
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            // If we found land that we haven't visited yet, we found a new island!
            if (grid[i][j] == 1 && !visited[i][j]) {
                islandCount++;
                // Explore and mark all connected land as visited
                dfs(grid, visited, i, j, rows, cols);
            }
        }
    }
    
    return islandCount;
}

void IslandCounter::dfs(vector<vector<int>>& grid, 
                       vector<vector<bool>>& visited, 
                       int i, int j, int rows, int cols) {
    // Check if we're outside the grid boundaries
    if (i < 0 || i >= rows || j < 0 || j >= cols) {
        return;
    }
    
    // If this is water or we've already visited this spot, stop exploring
    if (grid[i][j] == 0 || visited[i][j]) {
        return;
    }
    
    // Mark this land piece as visited so we don't check it again
    visited[i][j] = true;
    
    // Check & Explore all four directions: up, down, left, right
    // This will find all connected land pieces that form the same island
    dfs(grid, visited, i + 1, j, rows, cols); // down
    dfs(grid, visited, i - 1, j, rows, cols); // up
    dfs(grid, visited, i, j + 1, rows, cols); // right  
    dfs(grid, visited, i, j - 1, rows, cols); // left
}