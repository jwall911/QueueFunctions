#include <iostream>
#include "queueFun.h"

Queue q1;
 
            Queue::Queue() //default constructor
            {
                front = 0;
                rear = 0;
                elementsInQueue = 0;
            }

            void Queue::createQueue()
            {
                std::cout << "Please enter the size of your queue\n";
                std::cin >> MAX_SIZE;
                queueArray = new int(MAX_SIZE); //dynamically allocate memory to create array based queue
                created = true;
            }

            bool Queue::isCreated()
            {
                return created; //was the queue createD?
            }

            bool Queue::isEmpty() 
            {
                return {elementsInQueue == 0}; //are there elements in queue
            }

            bool Queue::isFull()
            {
                return {(rear+1)%MAX_SIZE == front}; //if rear + 1 is equal to front, then the list is empty -- using mod since array is circular for Queue implementation
            }

            void Queue::enqueue(int data)
            {
                std::cout << "Enqueueing " << data << "...\n";
                if (!isCreated())
                {
                    std::cout << "ERROR: Queue has not been created\n\n";
                        return;
                }
                else if (isEmpty()) //check if empty & set front and rear to proper positions
                {
                    front = rear = 0; //front and rear both equal 0 since it's empty                  
                }
                else if (isFull()) //check if full
                {
                    std::cout << "ERROR: Cannot enqueue " << data << "  as queue is FULL\n\n";
                    return;
                }
                else //queue has something in it already
                {
                     rear = (rear + 1)%MAX_SIZE; //increment rear position by 1 since it has something in it, using mod to keep array circular
                }
                queueArray[rear] = data; //add the data in the rear position
                std::cout << data << " has been successfully enqueued.\n";
                elementsInQueue++;
            }

            void Queue::dequeue()
            {
                std::cout << "Dequeueing...\n";
                if (isEmpty())
                {
                    std::cout<<"ERROR: Cannot dequeue as queue is EMPTY\n\n";
                    return;
                }
              else 
              {
                int data = queueArray[front];
                std::cout << data << " has been successfully dequeued.\n";
                elementsInQueue--;
                front += 1;
              }
            }

            int Queue::top()
            {
                if (!isEmpty())
                {
                    return queueArray[front];
                }
                else 
                {
                    return -1;
                }
            }

            void Queue::print()
            {
                int pos = front;
                std::cout << "Printing the queue...\n";
                if(!isEmpty())
                {
                    while(pos-1 != (rear))
                    {
                        if(pos == rear)
                        std::cout << queueArray[pos] << std::endl;
                        else
                        {
                        std::cout << queueArray[pos] << ", ";
                        }
                        pos++;
                    }
                    //std::cout << std::endl;
                }
                else 
                {
                    std::cout << "ERROR: There is no queue to print.\n\n";
                }
            }

            int Queue::getSize()
            {
                return MAX_SIZE;
            }

    



