#ifndef QUEUELINKEDLSIT_H_
#define QUEUELINKEDLSIT_H_
#include "QueueNode.h"
#include <iostream>
using namespace std;
class QueueLinkedList
{
    public:
        QueueNode * front;
        QueueNode *rear;
        QueueLinkedList() {
            front = nullptr;
            rear = nullptr;
        }
        //Enqueue --> insert elements into queue
        void enqueue(int data){
            QueueNode * newNode = new QueueNode(data);
            //if it's first node
            if (front == nullptr && rear == nullptr){
                front = rear= newNode;     //front, rear point at sameThing
            }
            else{
            rear->next = newNode;
            rear = newNode;  
        }
        }
        //Dequeue --> Display then remove elemnts from queue
        int dequeue(){
            int data=0;
            //if queue is empty
            if (front == nullptr){
                throw "Queue is empty ..";
            }
            //if there are old nodes 
            data = front->data;
            QueueNode *temp = front;
            front = front->next;
            if (front == nullptr){
                rear = nullptr;  
            }
            delete temp; 
            return data;
        }

        //Getfront -->return first element 
        int getFront(){
            if (front == nullptr){
                return -1;
            }
            return front->data;
        }

        //Getrear --> return last element
        int getRear(){
            if (rear == nullptr){
                return -1;
            }
            return rear->data;
        }
        void display(){
            if (front == nullptr && rear == nullptr){
                throw "Queue is empty ..";
                return;
            }
            cout<<"Queue Items: ";
            QueueNode* curr = front;
            while (curr != nullptr) {
                cout << curr->data << " --> ";
                curr = curr->next;
            }

        }
        ~QueueLinkedList() {
            while (front != nullptr) {
            QueueNode *temp = front;
            front = front->next;
            delete temp;
        }
        }
};

#endif // QUEUELINKEDLSIT_H_
