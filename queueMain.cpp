#include <iostream>
#include "queueFun.cpp"
#include "time.h"

void processOption(int option) 
{
    switch(option)
    {
        case 1:
        {
        srand(time(0));
        q1.createQueue();
        int num;
            for (int i = 0; i < MAX_SIZE; i++) //add random nums
            {
                num = rand()%100;
                q1.enqueue(num);
            }
        std::cout << "The queue is now full, what would you like to do?\n";
        break;
        }
        case 2:
        {
        int num;
        std::cout << "Please enter a number to be added to the queue\n";
        std::cin >> num;
        q1.enqueue(num);
        break;
        }
        case 3:
        {
        q1.dequeue();
        break;
        }
        case 4:
        {
        q1.print();
        break;
        }
    }
}

 int main()
        {
           int option = 0;
            do
            {
                std::cout << "1. Create new queue with random nums \n2. Add an element to the queue (enqueue)\n3. Remove an element from the queue (dequeue)\n4.Display all the elements in the queue\n5.Quit\n\n";
                std::cin >> option;
                processOption(option);

            } while(option != 5);
        }
