#include <iostream>
using namespace std;

int main() {
    int n;
    cout<<"Enter size of square: ";
    cin>>n;

    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            if(i==0 || j==0 || i==n-1 || j==n-1) {
                cout<<"* ";
            } else 
                cout<<"  ";
        }
        cout<<endl;
    }
    cout<<endl;


    int pin = 1234;
    int enteredCode;

    while(enteredCode != pin) {
        cout<<"Enter pin: ";
        cin>>enteredCode;
    }
    cout<<"Access granted!"<<endl;
}