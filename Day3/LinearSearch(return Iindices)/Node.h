#ifndef NODE_
#define NODE_

class Node
{
public:
    int data;
    Node* next;
    Node* prev;
    
    Node(int data) {
        this->data = data;
        next = nullptr;
        prev = nullptr;
    }
    ~Node() {}
};

#endif // NODE_
