#include  "Queue.h"
#include <stdio.h>
#include <iostream>

#define NUM 20

using std::cout;
using std::endl;



int main()
{
    Queue<int> queue1;
    for (int i = 1; i < NUM; i++)
    {
        queue1.pushBack(i);
    }

    cout << queue1.front() << endl;
    queue1.popFront();
    cout << queue1.front() << endl;
    queue1.popFront();
    cout << queue1.front() << endl;

    cout << queue1.size() << endl;
    

    Queue<int> queue2 = queue1;
    for(int i : queue1){
        cout << "queue 1: "<< i << "\n";
    }

    for(int i : queue2){
        cout << "queue 2: "<< i << "\n";
    }

    Queue<int> queue3 = queue1;
    queue2.popFront();
    queue2.popFront();
    queue2.popFront();
    queue3 = queue2;

    cout << "assignment operator test" << "\n";
    for(int i : queue2){
        cout << "queue 2: "<< i << "\n";
    }
    for(int i : queue3){
        cout << "queue 3: "<< i << "\n";
    }
    cout << "end of test" << endl;
    
    
}