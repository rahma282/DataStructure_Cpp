#include <iostream>
#include "LinkedList.h"
using namespace std;

int main()
{
    LinkedList list;

    list.add(5);
    list.add(1);
    list.add(4);
    list.add(2);
    list.add(3);

    cout << "Original Linked List: ";
    list.display();
    cout<<"------------------------------------"<<endl;

    list.bubbleSort();
    cout << "Sorted Linked List: ";
    list.display();
    cout<<"------------------------------------"<<endl;
    int target = 3;
    int result = list.binarySearch(target);
    
    if (result != -1) {
        cout << "Element " << target << " found at index: " << result << endl;
    } else {
        cout << "Element " << target << " not found in the list." << endl;
    }
    

    return 0;
}
