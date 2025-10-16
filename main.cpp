#include "CircularQueue.h"
#include <iostream>
using namespace std;

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
    q.display();  // Should show empty
    
    return 0;
}