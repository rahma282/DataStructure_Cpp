#include "LinkedList.h"
class Search
{
public:
    //handle cases where the array contains multiple occurrences of the target element.
    //Display all indices where the target
    LinkedList linearSearch(int * arr , int size , int target){
        LinkedList list;
        for (int i = 0; i < size; i++) {
            if (arr[i] == target) {
            list.add(i);  
            }
        }
        return list;
}
};


