#include <iostream>
using namespace std;
class CircleQueue{
    private:
        int front;
        int rear;
        int size;
        int * elements;
        int isEmpty (){
            if (front == -1 && rear == -1){
                return 1;
            }
            return 0;
        }
        int isFull(){
            if((front==0 && rear==size-1) || (rear+1==front)){
                return 1;
            }
            if (rear == front -1){
                return 0;
            }
            return 0;
        }
    public:
        CircleQueue(int _size){
            front = rear =-1;
            size = _size;
            elements = new int [size];
        }
        // Enqueue --> Insert element into the queue
        int enqueue(int data){
            if (isFull()){
                return 0;
            }
            if (isEmpty()){  //if it's first element 
                front = rear =0;
            }
            else if (rear == size-1){  //circle case
                rear =0;
            }
            else {              //normal case
                rear++;
            }
            elements[rear] = data;
            return 1;
        }
        // Dequeue --> Remove and return the front element
        int dequeue(){
            if (isEmpty()){
                throw "Queueu is empty..";
            }
            int data = elements[front];
            if (rear == front){  //circle case
                front = rear =-1;
            }
            else if (front == size-1){  //circle case
                front =0;
            }
            else {
                front++;
            }
            return data;
        }
        // GetFront --> Return the front element without removing it
        int getFront(){
            if (isEmpty()){
                return -1;
            }
            return elements[front];
        }
        // GetRear --> Return the rear element without removing it
        int getRear(){
            if (isEmpty()){
                return -1;
            }
            return elements[rear];
        }
        void display(){
            if (isEmpty()) {
            cout << "Queue is empty.." << endl;
            return;
        }
            cout << "Queue elements: ";
            int i = front;
            while (i != rear) {
                cout << elements[i] << "---> ";
                i = (i + 1) % size;  // circular behavior when i reaches the end of the array(i == size) it wraps back around to the beginning of the array
            }
            cout << elements[rear] << endl;  
        }
        ~CircleQueue(){
            delete[] elements;
        }
};
void print (){
    cout<<"------------------------------------------"<<endl;
}
int main()
{
    CircleQueue queue(5);
    try{
        queue.enqueue(10);
        queue.enqueue(20);
        queue.enqueue(30);
        queue.enqueue(40);
        queue.enqueue(50);
        queue.display(); 
        print();

        cout << "Dequeued Element: " << queue.dequeue() << endl;
        cout << "Dequeued Element: " << queue.dequeue() << endl;
        queue.display(); 
        print();

        queue.enqueue(60);
        queue.enqueue(70);
        queue.display();  
        print();

        cout << "Dequeued Element: " << queue.dequeue() << endl;
        cout << "Dequeued Element: " << queue.dequeue() << endl;
        cout << "Dequeued Element: " << queue.dequeue() << endl;
        cout << "Dequeued Element: " << queue.dequeue() << endl;
        cout << "Dequeued Element: " << queue.dequeue() << endl;
        cout << "Dequeued Element: " << queue.dequeue() << endl;  //Queue is empty..

    }catch (const char* e) {
        cout << e << endl;
    }

    return 0;
}
