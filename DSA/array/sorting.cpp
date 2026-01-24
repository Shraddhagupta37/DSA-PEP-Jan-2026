#include <iostream>
#include <vector>
using namespace std;

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void selectionSort(vector<int> &arr) {
    for(int i=0;i<arr.size()-1;i++) {
        int minIdx = i;
        for(int j=i+1;j<arr.size();j++) {
            if(arr[j] < arr[i])
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

int main() {
    vector<int> arr1 = {42,2,3,56,9,28,42,37,10};
    selectionSort(arr1);

    vector<int> arr2 = {10,15,2,25,16,12};
    bubbleSort(arr2);
}