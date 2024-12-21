#ifndef NODE_H_
#define NODE_H_


class Node
{
    public:
        int data;
        Node * Right;
        Node * Left;
        Node(int _data) {
            data = _data;
            Right =nullptr;
            Left = nullptr;
        }
        ~Node() {}
};

#endif // NODE_H_
