#include <iostream>
#include "LinkedList.h"
#include "Search.h"
using namespace std;

int main() {
    int arr[] = {1, 3, 5, 3, 7, 3};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 3;
    cout<<"Array Elements: ";
    for (int i = 0; i < size; i++)
    {
        cout<<"[ "<<arr[i]<<" ]";
    }
    
    Search search;
    LinkedList result = search.linearSearch(arr, size, target);

    cout << "\nIndices of target (" << target << "): ";
    result.display();
    return 0;
}
