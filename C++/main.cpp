#include <iostream>
using namespace std;

// <---- Creation of Partition Function ---->

int arrayPartition(int arr[], int lowerBound, int upperBound){
    int start = lowerBound;
    int end = upperBound;

    int key = arr[lowerBound];
    while (start < end) {
        while(arr[start] <= key){
            start++;
        }
        while(arr[end] > key){
            end--;
        }
        if(start < end){
            swap(arr[start], arr[end]);
        }
    }
    swap(arr[lowerBound],arr[end]);
    return end;
}

// <---- Creation of Quick Sort Recursive Function ---->


void QuickSort(int arr[], int lowerBound, int upperBound){
    if(lowerBound < upperBound){
        int index = arrayPartition(arr,lowerBound,upperBound);
        QuickSort(arr, lowerBound, index - 1);
        QuickSort(arr, index + 1, upperBound);
    }
}

int main(int argc, const char * argv[]) {
    int arr[] = {9,4,7,6,3,5,1,2};
    int size = sizeof(arr)/sizeof(arr[0]);
    
    QuickSort(arr, 0, size - 1);
    
    for(int i = 0; i <size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}


// Time Complexity
// 1) Worst Case: O(n^2)
// 2) Best Case: O(n*log(n))
// 3) Average Case: O(n*log(n))

