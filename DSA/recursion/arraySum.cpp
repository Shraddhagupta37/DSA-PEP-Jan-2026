#include <iostream>
using namespace std;

int findSum(int arr[], int size) {
    if(size == 0 || size == 1) {
        return arr[0];
    }
    return arr[0] + findSum(arr + 1, size - 1);
}

int main() {
    int arr[] = {2,4,3,1,6,9};
    int size = sizeof(arr)/sizeof(arr[0]);
    cout << findSum(arr, size) << endl;
}