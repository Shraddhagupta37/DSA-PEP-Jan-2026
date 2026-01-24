#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> nums = {5,4,3,2,1};
    vector<char> v2(5,'a');

    cout << nums.at(1);

    // cout << nums[6]; //gives 0
    // cout << nums.at(6); //throws out_of_range error 

    
}