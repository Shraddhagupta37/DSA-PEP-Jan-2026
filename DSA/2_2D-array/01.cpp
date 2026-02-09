#include <iostream>
using namespace std;

void print2DArray(int arr[3][4], int r, int c) {
    for(int i=0; i<r; i++) {
        for(int j=0; j<c; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

bool searchIn2DArray(int arr[3][4], int r, int c, int key) {
    for(int i=0; i<r; i++) {
        for(int j=0; j<c; j++) {
            if(arr[i][j] == key)
                return true;
        }
    }
    return false;
}

int main() {
    // int arr[][4] = {{1,2,3,4}, {5,6,7,8}, {9,10,11,12}};
    // int arr[3][4] = {1,2,3,4,5,6,7,8,9,10,11,12};
    
    int r, c;
    cout << "Enter no. of rows: ";
    cin >> r;
    cout << "Enter no, of columns: ";
    cin >> c;

    cout << "Enter array elements: ";
    int arr[r][c];
    for(int i=0; i<r; i++) {
        for(int j=0; j<c; j++) {
            cin >> arr[i][j];
        }
    }
    print2DArray(arr, r, c);

    //take column-wise input
    int arr2[r][c];
    cout << "Enter array elements column-wise: ";
    for(int j=0; j<c; j++) {
        for(int i=0; i<r; i++) {
            cin >> arr2[i][j];
        }
    }
    print2DArray(arr2, r, c);

    cout << searchIn2DArray(arr, r, c, 8);

    return 0;
}