#ifndef CIRCULARQUEUE_H
#define CIRCULARQUEUE_H

class CircularQueue{
    // Each node will store the data and points to the next node
    private:
    struct Node{
        int data;
        Node* next;
        Node(int value);

    };
    // Only needed one pointer here to point to the last one
    // First node: rear --> next 
    Node ** rear;


    public:
    CircularQueue();
    ~CircularQueue();


    //Enqueue add to end of queue
    void enqueue(int value);

    //Dequeue remove from front of queue
    void dequeue();

    //Peek look at front without removing it
    int peek();

    //Check if queue is empty 
    bool isEmpty();

    //Show all elements
    void display();
};

#endif

