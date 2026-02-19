#include <bits/stdc++.h>
using namespace std;

/*
Heap: a complete binary tree (CBT) that follows the heap order property
=> CBT: all levels are filled except the last level; the last level is filled left to right
=> Heap is not a BST

Heap order property: 
    -> Max Heap: 
        1. every parent node is greater than or equal to its children
        2. the largest element is always at root
    -> Min Heap: 
        1. every parent node is smaller than or equa; to its children
        2. the smallest element is always at root

    For 1-based indexing:
    - left child: 2 * i
    - right child: 2 * i + 1
    - parent: i / 2

    For 0-based indexing:
    - left child: 2 * i + 1
    - right child: 2 * i + 2
    - parent: (i - 1) / 2

*/

class MaxHeap {
    public: 
    vector<int> heap;
    int idx;

    MaxHeap() {
        idx = 0;
    }

    void heapify(int idx) {
        while(idx > 0) {
            int parent = (idx-1)/2;
            if(heap[idx] > heap[parent]) 
                swap(heap[idx], heap[parent]);
            else
                break;
            idx = parent;
        }       
    }

    void insert(int val) {
        heap.push_back(val);
        heapify(idx++);
    }

    void printHeap() {
        for(int x : heap) {
            cout << x << " ";
        }
        cout << endl;
    }
};

int main() {
    int n;
    cout << "Enter no. of elements to insert in heap: ";
    cin >> n;

    MaxHeap h;
    for(int i=1; i<=n; i++) {
        int val;
        cin >> val;
        h.insert(val);
    }

    cout << "Max Heap: ";
    h.printHeap();

}