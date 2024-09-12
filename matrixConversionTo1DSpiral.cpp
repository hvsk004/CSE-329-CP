#include<bits/stdc++.h>
using namespace std;
int main() {
    vector<vector<int>> matrix = {{1,2,3,4}, {5,6,7,8}, {9,10,11,12}};
    // Print the matrix
    cout << "The Input matrix is" << endl;
    for (const auto& row : matrix) {
        for (const auto& element : row) {
            cout << element << " ";
        }
        cout << endl;
    }
    // Convert the matrix to 1D spiral
    int rows = matrix.size();
    int cols = matrix[0].size();
    vector<int> spiral;
    int top = 0, bottom = rows - 1, left = 0, right = cols - 1;
    while (top <= bottom && left <= right) {
        for (int i = left; i <= right; i++) {
            spiral.push_back(matrix[top][i]);
        }
        top++;
        for (int i = top; i <= bottom; i++) {
            spiral.push_back(matrix[i][right]);
        }
        right--;
        if (top <= bottom) {
            for (int i = right; i >= left; i--) {
                spiral.push_back(matrix[bottom][i]);
            }
            bottom--;
        }
        if (left <= right) {
            for (int i = bottom; i >= top; i--) {
                spiral.push_back(matrix[i][left]);
            }
            left++;
        }
    }
    cout << "The Spiral 1D Vector is : " << endl;
    for(int &i : spiral) {
        cout << i << " ";
    }
    return 0;
}
//Time Complexity: O(N*M)