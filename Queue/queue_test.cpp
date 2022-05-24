#include  "Queue.h"
#include <stdio.h>
#include <iostream>

using std::cout;
using std::endl;



int main()
{
    Queue<int> queue1;
    queue1.pushBack(5);
    queue1.pushBack(3);
    queue1.pushBack(4);
    queue1.pushBack(6);
    queue1.pushBack(7);

    cout << queue1.front() << endl;
    queue1.popFront();
    cout << queue1.front() << endl;
    queue1.popFront();
    cout << queue1.front() << endl;


}