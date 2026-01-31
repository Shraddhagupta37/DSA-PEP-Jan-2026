#include <bits/stdc++.h>
using namespace std;

// void merge(int arr[], int s, int e) {
//     int mid = (s + e) / 2;
//     int i = s, j = mid + 1;
//     int temp[e - s + 1];
//     int k = 0;

//     while (i <= mid && j <= e) {
//         if (arr[i] < arr[j])
//             temp[k++] = arr[i++];
//         else
//             temp[k++] = arr[j++];
//     }

//     while (i <= mid) temp[k++] = arr[i++];
//     while (j <= e) temp[k++] = arr[j++];

//     for (int idx = 0; idx < k; idx++)
//         arr[s + idx] = temp[idx];
// }

void merge(int arr[], int s, int e) {
    int mid = (s+e)/2;
    int length1 = mid-s+1;
    int length2 = e-mid;
    int k = s;

    int *arr1 = new int[length1];
    int *arr2 = new int[length2];

    //copy first half of arr to arr1
    for(int i=0; i<length1; i++) {
        arr1[i] = arr[k++];
    }

    //copy second half of arr to arr2
    for(int i=0; i<length2; i++) {
        arr2[i] = arr[k++];
    }

    //update original array with sorting 
    int i = 0, j = 0;
    k = s;
    while(i<length1 && j<length2) {
        if(arr1[i] < arr2[j]) {
            arr[k++] = arr1[i++];
        } else {
            arr[k++] = arr2[j++];
        }
    }

    while(i<length1) {
        arr[k++] = arr1[i++];
    }

    while(j<length2) {
        arr[k++] = arr2[j++];
    }

    //delete the temporary dynamic arrays
    delete[] arr1;
    delete[] arr2;
}
 
void mergeSort(int arr[], int s, int e) {
    if(s>=e) return;
    int mid = (s+e)/2;
    mergeSort(arr,s,mid);
    mergeSort(arr,mid+1,e);

    merge(arr, s, e);

}

int main() {
    int arr[] = {2,5,1,6,7,3,10};
    int size = sizeof(arr)/sizeof(arr[0]);
    mergeSort(arr,0, size-1);

    for(int i=0; i<size; i++) {
        cout<<arr[i]<<" ";
    }
}