#ifndef QUEUEFUN_H
#define QUEUEFUN_H
int MAX_SIZE; //max size of array(array based queue)

class Queue 
{
    private: 
            int* queueArray; //pointer to int to create an array
            int front, rear, elementsInQueue; //self explanatory
            bool created = false;
    public: 
            Queue(); //default constructor
            void createQueue();
            bool isEmpty(); //checks if queue is empty
            bool isFull(); //checks if queue is full
            bool isCreated(); //check if queue is created
            void enqueue(int data); //adds to queue (which is always added to rear)
            void dequeue(); //removes from queue (which is always removed from front)
            void print(); //prints the data in the queue, starting at front
            int getSize(); //return size of queue as an int
            int top(); //returns what data is at the front without extracting
            
};


#endif