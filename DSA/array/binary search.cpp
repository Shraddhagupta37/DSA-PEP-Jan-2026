#include <iostream>
using namespace std;

int binarySearch(int arr[], int size, int key) {
    int s = 0;
    int e = size-1;

    while(s <= e) {
        int mid = (s+e)/2;
        if(arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            s = mid + 1;
        else
            e = mid - 1;
    }
    return -1;
}

int main() {
    int arr[] = {5, 17, 25, 32, 43, 58, 67, 71, 82, 98};
    int key;
    cout << "Enter key: ";
    cin >> key;

    int idx = binarySearch(arr, 10, key);
    cout << ((idx == -1) ? ("Key not found") : ("Key found at index "+idx)) << endl;
}