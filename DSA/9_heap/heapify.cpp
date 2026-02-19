#include <bits/stdc++.h>
using namespace std;

void heapify(vector<int> &heap, int n, int i) {
    int largest = i;
    int left = 2*i+1;
    int right = 2*i+2;

    if(left < n && heap[left] > heap[largest])
        largest = left;
        
    if(right < n && heap[right] > heap[largest])
        largest = right;

    if(largest != i) {
        swap(heap[i], heap[largest]);
        heapify(heap, n, largest);
    } 
}

//in heap, the elements from n/2 - n will already be in correct pos, and hence don't need to be checked
void builldMaxHeap(vector<int> &arr) {
    int n = arr.size();
    for(int i=n/2-1; i>=0; i--) {
        heapify(arr, n, i);
    }
}

int main() {
    int n;
    cout << "Enter no. of elements to insert in heap: ";
    cin >> n;

    vector<int> arr;
    for(int i=0; i<n; i++) {
        int val;
        cin >> val;
        arr.push_back(val);
    }

    cout << "Original array: ";
    for(int x : arr) {
        cout << x << " ";
    }
    cout << endl;

    builldMaxHeap(arr);

    cout << "After heapify: ";
    for(int x : arr) {
        cout << x << " ";
    }
    cout << endl;

}