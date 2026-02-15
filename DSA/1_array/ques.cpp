#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int count = 1;
        int i = 0;
        while(i<nums.size()-1) {
            if(nums[i] == nums[i+1]-1) {
                count++;
            }
            i++;
        }

        return count;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {0, 3, 7, 2, 5, 8, 4, 6, 0, 1};
    cout << "Longest consecutive sequence length: " << sol.longestConsecutive(nums) << endl;
}