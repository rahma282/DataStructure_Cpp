#ifndef STACKNODE_
#define STACKNODE_


class StackNode
{
    public:
        int data;
        StackNode * prev;
        StackNode(int _data) {
            data = _data;
            prev = nullptr;
        }
        ~StackNode() {}
};

#endif // STACKNODE_
