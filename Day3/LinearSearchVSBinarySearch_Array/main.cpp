#include <iostream>

using namespace std;
void swapArray(int& first ,int& second){
    int temp = first;
    first = second;
    second = temp;
}
void bubbleSort(int * arr , int size){
    int sorted = 0;
    for (int outer = 0; sorted == 0; outer++) {
        sorted = 1;
        for (int inner = 0; inner < size - 1 - outer; inner++) { 
            if (arr[inner] > arr[inner + 1]) {
                swapArray(arr[inner], arr[inner + 1]);
                sorted = 0;
            }
        }
    }
}
int linearSearch(int * arr , int size , int target){
     int iteration = 0;
     int index=-1;
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            index = i;  
        }
        iteration++;
    }
    cout << "\nNO Of Iterations Using LinearSearch: " << iteration << endl<<"Linear Search Result: ";
    return index;
}
int binarySearch(int *arr, int size, int target) {  
    int start = 0;
    int end = size - 1;
    int middle = 0;
    int iteration = 0;

    while (start <= end) {
        middle = (start + end) / 2;
        iteration++;
        if (arr[middle] == target) {
            cout << "BinarySearch: NO Of Iterations " << iteration << endl;
            cout << "Binary Search Result: ";
            return middle;
        }
        if (arr[middle] < target) {  
            start = middle + 1;  // search from the right half
        } 
        else if (arr[middle] > target) {
            end = middle - 1;  // search from the left half
        }
        
    }
    cout << "BinarySearch: NO Of Iterations " << iteration << endl;
    return -1; 
}
int main()
{
    int arr[] = {2,5,8,4,0};   
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 4;
    bubbleSort(arr, size); //0 2 4 5 8

    cout<< linearSearch(arr, size, target) << endl;
    cout<< binarySearch(arr, size, target) << endl;

    return 0;
}
