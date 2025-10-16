#include "CircularQueue.h"
#include <iostream>
using namespace std;

// Node constructor 

CircularQueue::Node::Node(int value){
    data = value;
    next = nullptr;
}

// Memory clean up when queue is destroyed
CircularQueue::~CircularQueue(){
    while (!isEmpty()){
        dequeue();
    }
}

// Check if queue has no elements
bool CircularQueue::isEmpty() {
    return rear == nullptr;
}

// Add element to end of queue
void CircularQueue::enqueue(int value) {
    // Create new node
    Node* newNode = new Node(value);
    
    if (isEmpty()) {
        // First node - points to itself
        rear = newNode;
        rear->next = rear;
    } else {
        // Add to end of existing queue
        newNode -> next = rear -> next;  // New node points to front
        rear -> next = newNode;        // Old rear points to new node
        rear = newNode;              // New node becomes rear
    }
}

// Remove element from front of queue
int CircularQueue::dequeue{
    if (isEmpty()){
        cout < "Queue is empty!" << endl;
        return - 1;
    }
    // Front is always rear -> next
    Node* front = rear -> next;
    int value = front -> data;
    
    if (front == rear){
        // Only one element - queue becomes empty
        delete front;
        rear = nullptr;

    } else{
        // Multiple elements - remove front
        rear -> next = front -> next; 
        delete front;
    }

    return value;


}


//Look at front element without removing it
int CircularQueue::peek() {
    if (isEmpty()){
        cout << "Cannot peek - queue is empty!" << endl;
        return -1;
    }
    return rear->next->data;
}

void CircularQueue::display() {
    cout << "\n--- Display Queue ---" << endl;
    
    if (isEmpty()) {
        cout << "This queue is empty" << endl;
        return;
    }
    
    cout << "Queue contents (front to rear): ";
    Node* current = rear->next;
    Node* start = current;
    
    do {
        cout << current->data << " ";
        current = current->next;
    } while (current != start);
    
    cout << endl;
    cout << "Front: " << rear->next->data << ", Rear: " << rear->data << endl;
}