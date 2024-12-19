#include <iostream>
#include "QueueLinkedList.h"
using namespace std;
void print (){
    cout<<"-----------------------------------------------"<<endl;
}
int main()
{
   QueueLinkedList q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.display(); 
    print(); 

    cout << "Front: " << q.getFront() << endl;  
    print(); 
    cout << "Rear: " << q.getRear() << endl;    
    print(); 

    try {
    cout << "Dequeued: " << q.dequeue() << endl;  
    q.display(); 
    print(); 

    cout << "Dequeued: " << q.dequeue() << endl;  
    cout << "Dequeued: " << q.dequeue() << endl;  
    print(); 

    
    cout << "Dequeued: " << q.dequeue() << endl;  //Queue is empty ..
    } catch (const char* e) {
        cout << e << endl;
    }
    return 0;
}

