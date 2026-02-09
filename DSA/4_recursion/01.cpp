#include <bits/stdc++.h>
using namespace std;

//head recursion
void print1toN(int n) {
    if(n==0) return;
    print1toN(n-1);
    cout << n << " ";
}

//tail recursion
void printNto1(int n) {
    if(n==0) return;
    cout << n << " ";
    printNto1(n-1);
}

void printEven(int n) {
    n = n%2==0 ? n-2 : n-1;
    if(n==0) return;
    printEven(n);
    cout << n << " ";
}

long long factorial(int n) {
    if(n==1 || n==0) return 1;
    return n * factorial(n-1);
}

long long calcPower(int x, int p) {
    if(p==0) return 1;
    return x * calcPower(x, p-1);
}

int fibonacci(int n) {
    if(n==1) {
        return 0;
    }
    if(n==2) {
        return 1;
    }
    int res = fibonacci(n-1) + fibonacci(n-2);
    // cout << res << " ";
    return res;
}

int main() {
    int n = 5;
    print1toN(n);
    cout << endl;
    printNto1(n);

    cout << endl;
    int N = 9;
    printEven(N);

    cout << endl;
    cout << factorial(5) << endl;

    cout << calcPower(2,5) << endl;

    cout << fibonacci(8) << endl;
}