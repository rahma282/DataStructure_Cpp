#include "Tree.h"
#include "Node.h"
#include <iostream>
using namespace std;
void print (){
    cout<<"--------------------------------------------"<<endl;
}
int main() {
    Tree tree;

    tree.add(50);
    tree.add(30);
    tree.add(70);
    tree.add(20);
    tree.add(40);
    tree.add(60);
    tree.add(80);

    cout << "Tree Elements: " << endl;
    tree.displayAll(); // Display all elements in the tree
    cout << endl;
    print();

    int data = 40;
    if (tree.findDataInTree(data)) {
        cout << "Data " << data << " found in the tree." << endl;
    } else {
        cout << "Data " << data << " not found in the tree." << endl;
    }
    print();
    
    try {
        int parentData = tree.getPerantBydata(40);
        cout << "Parent of node 40 is: " << parentData << endl;
    } catch (const char* e) {
        cerr << e << endl;
    }
    print();
    
    try {
        int maxRight = tree.getMaxRightByData(30);
        cout << "Maximum node to the right of node 30 is: " << maxRight << endl;
    }catch(const char * msg){
        cout<<msg;
    }
    print();

    try {
        cout << "Minimum node in the tree: " << tree.getMinimumNode() << endl;
        cout << "Maximum node in the tree: " << tree.getMaximumNode() << endl;
    } catch(const char * msg){
        cout<<msg;
    }
    print();

    
    try {
        cout << "Removing node 70." << endl;
        tree.remove(70);
        tree.displayAll();
        cout << endl;
    } catch(const char * msg){
        cout<<msg;
    }
    print();

    return 0;
}
