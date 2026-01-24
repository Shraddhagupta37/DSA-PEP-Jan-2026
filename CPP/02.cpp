#include <iostream>
using namespace std;

void hello() {
    cout << "Hello!" << endl;
}

int add() {
    return 10;
}

float sub(float a,float b) {
    return a-b;
}

int main() {
    hello();
    cout<< add() * 10 << endl;
    cout << sub(8.5,3.2) << endl;
}