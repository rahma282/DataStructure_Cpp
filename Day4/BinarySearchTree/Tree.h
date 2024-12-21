#ifndef TREE_H_
#define TREE_H_
#include "Node.h"
#include <iostream>
using namespace std;
class Tree
{
    private:
        Node * root;
        //helper functions
        //getNodeByData
        Node * getNodeByData(int data){
            Node * current = root;
            while (current != nullptr){
                if (data == current->data){
                    return current;
                }
                else if (data > current->data){
                    current = current->Right;
                }
                else if (data <= current->data){
                    current = current->Left;
                }
            }
            return nullptr;
        }
        Node * getPerant(Node * node){
            Node * perant = root;
            while(perant != nullptr){
                if (node == perant->Right || node ==perant->Left){
                    return perant;
                }
                else if (node->data >perant->data){
                    perant = perant->Right;
                }
                else{
                    perant = perant->Left;
                }
            }
            return nullptr;
        }
        Node *getMaxRight(Node * node){
            Node * current = node;
            while(current->Right !=nullptr){
                current = current->Right;
            }
            return current;
        }
        void display(Node * node){
            if (node == nullptr){
                return;
            }
            display(node->Left);
            cout<<node->data<<" : ";
            display(node->Right);
        }
    public:

        Tree() {
            root = nullptr;
        }
        void add (int data){
            //create node into heap
            Node * newNode = new Node(data);
            //if it's first node
            if (root == nullptr){
                root = newNode;
            }
            else{//if it's not the first --> check if data>curr.data -> right else ->left
                Node * current = root;
                Node * perant = nullptr;  //one step before current --> if current ==null i want paretnt to put data in newNode
                while (current !=nullptr){
                    perant = current;
                    if (data > current->data){
                        current = current->Right;
                    } else{//(data < current->data)
                        current = current->Left;
                    }
                } 
                //put data in newnode
                if (data > perant->data){
                    perant->Right = newNode;
                }
                else{
                    perant->Left = newNode;
                }
            }
        }
        int findDataInTree(int data){
            if (getNodeByData(data) == nullptr){
                return 0;  //not found
            }
            return 1; //found
        }
        int getPerantBydata(int data){
        Node * node = getNodeByData(data);
        if(node == root){
            throw "The Node is Root Not Have Parent";
        }
        if(node != nullptr ){
            Node * parent=getPerant(node);
            if(parent != nullptr){
                return parent->data;
            }
        }else{
            throw " Node Not Found , Not Have Parent";
        }
    }
        int getMaxRightByData(int data){
        Node * node=getNodeByData(data);
        if(node == nullptr){
            throw " Node Not Found";
        }
        Node * maxR= getMaxRight(node);
        return maxR->data;
    }
    void remove(int data){ //remove root or any node in the tree
        //search node 
        Node * node = getNodeByData(data);
        if (node == nullptr){
            throw "Error: not found node i can't remove..";
        }
        //if this node is root there is 3 options 
        //1.if the root is the only node
        if (node == root){
            if (root->Left == nullptr&&root->Right == nullptr){
                root->Right = nullptr;
            }
            //2.if root have right node or left node only 
            else if (root->Left == nullptr){  //there is node in the right of root
                root = root->Right;
            }
            else if (root->Right == nullptr){  //there is node in the Left of root
                root = root->Left;
            }
            //3.if root have nodes in left and right 
            else {
                //define the first left child as new root
                Node * newRoot = root->Left;
                //get maxRight of FLC
                Node * maxR = getMaxRight(newRoot);
                //build new connnection (link root right side with the right side of MaxR of FLC)
                maxR->Right = root->Right;
                root = newRoot;
        }
        }
        else{
            //if i remove any node but not root
            Node * perant = getPerant(node);
            Node * newChild = nullptr;
            if (node->Left == nullptr && node->Right == nullptr) {
                newChild = nullptr;
            }
            //2.if node have right child or left child only 
            else if (node->Left == nullptr){  //there is child in the right of node
                newChild = node->Right;
            }
            else if (node->Right == nullptr){  //there is child in the Left of node
                newChild = node->Left;
            }
            //3.if node have childs in left and right 
            else {
                //define the first left child as new node
                Node * newPerant = node->Left;
                //get maxRight of FLC
                Node * maxR = getMaxRight(newPerant);
                //build new connnection (link node right side with the right side of the parent of her parent)
                maxR->Right = node->Right;
                newChild = newPerant;
            }
            if(perant->Right ==node){
                perant->Right =newChild;
            }
            else{
                perant->Left =newChild;
            }
        }
        delete node;
    }
    int getMinimumNode()
    {
        if(root==nullptr)
        {
            throw "There is no Node in the tree..";
        }
        Node* current=root;
        while(current->Left!=nullptr)
        {
            current=current->Left;
        }
        return current->data;
    }
    int getMaximumNode()
    {
        if(root==nullptr)
        {
            throw"There is no Node in the tree..";
        }
        Node* current=root;
        while(current->Right!=nullptr)
        {
            current=current->Right;
        }
        return current->data;
    }
    void displayAll(){
        display(root);
    }
        ~Tree() {}

    
};

#endif // TREE_H_
