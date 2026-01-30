// Problem: 
// Given a staircase of N steps and you can climb either 1 or 2 steps at a time. The task is to return the number of distinct ways to reach the top.
// Note: The order of the steps taken matters.

// Example:
// Input: N = 3
// Output: 3
// Explanation: There are three ways to reach the 3rd step.
// [1,1,1], [1,2], [2,1]


#include <iostream>
using namespace std;

int fibonacci(int n) {
    if(n==1) {
        return 1;
    }
    if(n==2) {
        return 2;
    }
    int res = fibonacci(n-1) + fibonacci(n-2);
    return res;
}

int countWays(int n) {
    // Since the number of ways to reach the nth step is equivalent to the (n+1)th Fibonacci number
    return fibonacci(n);
}

int main() {
    int N = 3;
    cout << "Number of ways to reach the top of " << N << " steps: " << countWays(N) << endl;

    N = 5;
    cout << "Number of ways to reach the top of " << N << " steps: " << countWays(N) << endl;

    return 0;
}