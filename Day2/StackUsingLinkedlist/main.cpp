#include <iostream>
#include "StackLinkedList.h"
using namespace std;

int main()
{
    StackLinkedList stack;

    try {
        stack.push(10);
        stack.push(20);
        stack.push(30);
        stack.display();

        cout << "Peeked element: " << stack.peek() << endl;

        cout << "Popped element: " << stack.pop() << endl;
        cout << "Popped element: " << stack.pop() << endl;
        stack.display();

        cout << "Popped element: " << stack.pop() << endl;

        // try to pop from an empty stack ..
        cout << "Popped element: " << stack.pop() << endl; 

    } catch (const char* e) {
        cout << e << endl;
    }

    return 0;
}