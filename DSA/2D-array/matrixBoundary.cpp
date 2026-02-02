#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> boundaryTraversal(vector<vector<int>>& mat) {
        // code here
        vector<int> result;
        int r = mat.size(), c = mat[0].size();
        
        int top = 0, bottom = r - 1;
        int left = 0, right = c - 1;
        
        for(int i=left; i<=right; i++) {
            result.push_back(mat[top][i]);
        }
        top++;
        
        if(top <= bottom) {
            for(int i=top; i<=bottom; i++) {
                result.push_back(mat[i][right]);
            }
            right--;
            
            if(left <= right) {
                for(int i=right; i>=left; i--) {
                    result.push_back(mat[bottom][i]);
                }
                bottom--;
                
                if(top <= bottom) {
                    for(int i=bottom; i>=top; i--) {
                        result.push_back(mat[i][left]);
                    }
                    left++;
                }
            }
        }
        
        return result;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> mat = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };
    
    vector<int> boundary = sol.boundaryTraversal(mat);
    
    cout << "Boundary Traversal: ";
    for(int val : boundary) {
        cout << val << " ";
    }
    cout << endl;
    
    return 0;
}