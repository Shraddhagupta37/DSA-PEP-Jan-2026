#include <bits/stdc++.h>
using namespace std;

int partition(int arr[], int s, int e) {
    //initialize pivot as arr[s]
    int pivot = arr[s];

    //count no. of elements less than pivot
    int count = 0;
    for(int i=s+1; i<=e; i++) {
        if(arr[i] < pivot)
            count++;
    }

    //pivot element's correct position will be after no. of elements less than it
    int pivotIdx = s + count;
    swap(arr[pivotIdx], arr[s]);

    //handle the left of pivot so that it only contains elements less than it, and the right of pivot so that it contains elements greater than it
    int i = s, j = e;
    while(i<pivotIdx && j>pivotIdx) {
        while(arr[i] < pivot) i++;
        while(arr[j] > pivot) j--;

        swap(arr[i++], arr[j--]);
    }

    return pivotIdx;
}

void quickSort(int arr[], int s, int e) {
    if(s >= e) return;
    
    int p = partition(arr, s, e);
    
    quickSort(arr, s, p-1);
    quickSort(arr, p+1, e);
}

int main() {
    int arr[] = {21,19,17,14,13,9,8,6,3,2};
    int size = sizeof(arr)/sizeof(arr[0]);
    quickSort(arr, 0, size-1);

    for(int i=0; i<size; i++) {
        cout<<arr[i]<<" ";
    }
}