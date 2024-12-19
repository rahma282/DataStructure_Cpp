#ifndef STACKLINKEDLIST_
#define STACKLINKEDLIST_
#include "StackNode.h"
#include <iostream>
#include <stdexcept>
using namespace std;

class StackLinkedList
{
    public:
        StackNode * tail; 
        StackLinkedList() {
            tail = nullptr;
        }
        //push -->insert elemnts into stack
        void push (int data){
            // create new node
            StackNode * newNode = new StackNode(data);
            if (tail == nullptr) {  // if it's the first node
                tail = newNode;
            } else {
                // link new node to the current stack
                newNode->prev = tail;
                tail = newNode;
            }
        }
        //pop --> display then remove the last element entered LIFO
        int pop (){
            int data =0;
            //if stack is empty
            if (tail == nullptr){
               throw "Stack is empty..";
            }
            //if there are nodes
            StackNode * temp = tail;
            data = tail->data;
            tail = tail->prev;
            delete temp;
            return data; 
        }
        //peek --> return the last element entered
        int peek(){
            //if stack is empty
            if (tail == nullptr){
             throw "Stack is empty..";
            }
            return tail->data;
        }
        void display(){
            if (tail == nullptr) {
            cout << "Stack is empty.." << endl;
            return;
            }
            cout<<"Stack Items: ";
            StackNode* curr = tail;
            while (curr != nullptr) {
                cout << curr->data << " --> ";
                curr = curr->prev;
            }
            

        }
        ~StackLinkedList() {
            while (tail != nullptr) {
            StackNode* temp = tail;
            tail = tail->prev;
            delete temp;
            }
        }

};

#endif // STACKLINKEDLIST_
