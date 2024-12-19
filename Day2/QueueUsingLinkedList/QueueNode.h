#ifndef QUEUENODE_H_
#define QUEUENODE_H_


class QueueNode
{
    public:
        int data;
        QueueNode * next;
        QueueNode(int _data) {
            data = _data;
            next = nullptr;
        }
        ~QueueNode() {}
};

#endif // QUEUENODE_H_
