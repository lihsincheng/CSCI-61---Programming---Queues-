#include "CircularQueue.h"
#include "IslandCounter.h"
#include "IslandCounter.cpp"
#include <iostream>
#include <vector>
using namespace std;


void printMatrix(const vector<vector<int>>& grid) {
    for (const auto& row : grid) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
}

int main() {
    CircularQueue q;
    
    // Testing for basic operations
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    
    q.display();  // Should show: 10 20 30
    
    cout << "Front: " << q.peek() << endl;  // Should show 10
    
    q.dequeue();
    q.display();  // Should show: 20 30
    
    // Test empty queue
    q.dequeue();
    q.dequeue();
    q.display();  
    

    cout << "\n=== TESTING ISLAND COUNTER ===" << endl;
    IslandCounter counter;
    
    // This is the example grid from the problem - it should have 5 islands
    vector<vector<int>> grid = {
        {1, 1, 0, 0, 1, 0},
        {1, 1, 0, 1, 1, 1},
        {0, 0, 0, 0, 0, 1},
        {0, 1, 0, 0, 0, 0},
        {0, 0, 0, 1, 0, 0},
        {1, 0, 1, 1, 0, 0}
    };
    
    cout << "Here's our grid (1 = land, 0 = water):" << endl;
   printMatrix(grid);
    
    int result = counter.countIslands(grid);
    cout << "\nWe found " << result << " islands in the grid!" << endl;
    

    return 0;
}


