#include <iostream>
using namespace std;

bool findKey(int arr[], int size, int key) {
    if(size == 0)
        return false;
    if(arr[0] == key)
        return true;
    return findKey(arr + 1, size - 1, key);
}

bool findKeyBinary(int arr[], int l, int r, int key) {
    if(l>r) return false;

    int mid = (l+r)/2;
    if(arr[mid] == key)
        return true;
    else if (arr[mid] < key)
        return findKeyBinary(arr, mid+1, r, key);
    else
        return findKeyBinary(arr, l, mid-1, key);    
}

int main() {
    int arr[] = {2,41,36,12,82,9};
    int size = sizeof(arr)/sizeof(arr[0]);
    cout << findKey(arr, size, 8) << endl;

    int arr2[] = {2,9,12,36,41,82};
    size = sizeof(arr2)/sizeof(arr2[0]);
    cout << findKeyBinary(arr2, 0, size-1, 12) << endl;
}