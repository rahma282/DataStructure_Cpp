#ifndef LINKEDLIST_
#define LINKEDLIST_

#include "Node.h"
#include <iostream>

using namespace std;

class LinkedList {
public:
    Node* head;
    Node* tail;
    int size; // Track the size of the LinkedList

    LinkedList() : head(nullptr), tail(nullptr), size(0) {}

    void add(int data) {
        Node* newNode = new Node(data);
        size++;
        if (head == nullptr) { // LinkedList is empty
            head = newNode;
            tail = newNode;
        } else { // Add to the end
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void insertAfter(int targetData, int data) {
        Node* targetNode = getNodeUsingData(targetData);
        if (targetNode == nullptr) {
            cout << "Target element not found in the list." << endl;
            return;
        }

        Node* newNode = new Node(data);
        size++;

        newNode->next = targetNode->next;
        newNode->prev = targetNode;

        if (targetNode->next != nullptr) { // Not inserting at the tail
            targetNode->next->prev = newNode;
        } else { // Inserting at the tail
            tail = newNode;
        }

        targetNode->next = newNode;
    }

    void insertBefore(int targetData, int data) {
        Node* targetNode = getNodeUsingData(targetData);
        if (targetNode == nullptr) {
            cout << "Target element not found in the list." << endl;
            return;
        }

        Node* newNode = new Node(data);
        size++;

        newNode->next = targetNode;
        newNode->prev = targetNode->prev;

        if (targetNode->prev != nullptr) { // Not inserting at the head
            targetNode->prev->next = newNode;
        } else { // Inserting at the head
            head = newNode;
        }

        targetNode->prev = newNode;
    }

    bool getDataByIndex(int index, int& outData) {
        if (index < 0 || index >= size) {
            return false; // Invalid index
        }

        Node* current = head;
        int currentIndex = 0;

        while (current != nullptr) {
            if (currentIndex == index) {
                outData = current->data;
                return true;
            }
            current = current->next;
            currentIndex++;
        }
        return false;
    }

    void display() const {
        Node* current = head;
        if (current == nullptr) {
            cout << "LinkedList is empty." << endl;
            return;
        }

        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    bool remove(int data) {
        Node* current = getNodeUsingData(data);

        if (current == nullptr) {
            cout << "Element not found in the list." << endl;
            return false;
        }

        if (current == head && current == tail) { // Single node
            head = nullptr;
            tail = nullptr;
        } else if (current == head) { // First node
            head = head->next;
            head->prev = nullptr;
        } else if (current == tail) { // Last node
            tail = tail->prev;
            tail->next = nullptr;
        } else { // Middle node
            current->prev->next = current->next;
            current->next->prev = current->prev;
        }

        delete current;
        size--;
        return true;
    }

    int getSize() const {
        return size;
    }
    void bubbleSort(){
        if (size <=1){  //already sorted cause there is one element
                return;
        }
        bool sorted;
        do {
                sorted = true;
                Node* current = head;
                while(current != nullptr&& current->next != nullptr){
                    if (current->data > current->next->data){
                        swapList(current->data, current->next->data);
                        sorted = false;
                    }
                    current = current->next;
                }
        }while (!sorted);
    }
     
     
    ~LinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
    }

private:
    Node* getNodeUsingData(int data) const {
        Node* current = head;
        while (current != nullptr) {
            if (current->data == data) {
                return current;
            }
            current = current->next;
        }
    }
    void swapList(int& f , int& s){
    int temp = s;
    s=f;
    f=temp;
}

};

#endif // LINKEDLIST_
