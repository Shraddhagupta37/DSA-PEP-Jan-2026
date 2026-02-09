#include <iostream>
#include <vector>
using namespace std;

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void printArray(const vector<int> &arr) {
    for(int i=0;i<arr.size();i++) {
        if(i == arr.size()-1)
            cout << arr[i] << endl;
        else
            cout << arr[i] << " ";
    }
}

void selectionSort(vector<int> &arr) {
    for(int i=0;i<arr.size()-1;i++) {
        int minIdx = i;
        for(int j=i+1;j<arr.size();j++) {
            if(arr[j] < arr[minIdx])
                minIdx = j;
        }
        swap(arr[i], arr[minIdx]);
    }
}

void bubbleSort(vector<int> &arr) {
    for(int i=0; i<arr.size()-1; i++) {
        for(int j=0; j<arr.size()-1-i; j++) {
            if(arr[j] > arr[j+1]) 
                swap(arr[j],arr[j+1]);
        }
    }
}

void insertionSort(vector<int> &arr) {
    for(int i=1;i<arr.size();i++) {
        int key = arr[i];
        int j = i-1;
        while(j>=0 && arr[j]>key) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

int main() {
    vector<int> arr1 = {42,2,3,56,9,28,42,37,10};
    selectionSort(arr1);
    printArray(arr1);

    vector<int> arr2 = {10,15,2,25,16,12};
    bubbleSort(arr2);
    printArray(arr2);

    vector<int> arr3 = {42,2,3,56,9,28,42,37,10};
    insertionSort(arr3);
    printArray(arr3);
}