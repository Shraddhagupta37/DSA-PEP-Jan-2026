#include <iostream>
#include <vector>
using namespace std;

int linearSearch(vector<int> arr, int key) {
    for (int i = 0;i<arr.size();i++) {
        if (arr[i] == key && key>5)
            return key*2;
        else if (arr[i] == key && key<5)
            return key/2;
    }
    return -1;
}

int main() {
    vector<int> arr = {12, 32, 5, 46, 84, 72, 96, 48};
    int key;

    cout << "Enter key: ";
    cin >> key;

    int result = linearSearch(arr, key);
    // cout << (idx == -1) ? "Key not found" : ("Key found at index "+idx);
    cout << result << endl;
}