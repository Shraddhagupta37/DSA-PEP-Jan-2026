#include <iostream>
using namespace std;

bool isSorted(int arr[], int size) {
    if( size == 0 || size == 1 ) {
        return true;
    }
    if(arr[0] > arr[1]) {
        return false;
    }
    return isSorted(arr + 1, size -1);
}

int main() {
    int arr1[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr1)/sizeof(arr1[0]);
    cout << isSorted(arr1, size) << endl;

    int arr2[] = {3, 4, 6, 2, 1};
    int size2 = sizeof(arr2)/sizeof(arr2[0]);
    cout << isSorted(arr2, size2) << endl;
}