#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    void reverse(int arr[], int n){
        if(n == 1 || n==0) return;
        swap(arr[0],arr[n-1]);
        reverse(arr + 1, n - 2);
    }
};

int main() {
    Solution sol;
    int arr[] = {1,2,3,4,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    sol.reverse(arr, n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}