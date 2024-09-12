#include<bits/stdc++.h>
using namespace std;
int main() {
    vector<vector<int>> matrix = {{1,2,3,4}, {5,6,7,8},{9,10,11,12},{13,14,15,16}};
    int rows = matrix.size();
    int cols = matrix[0].size();
    int i = 0, j = 0;
    int dir = 0;
    int count = 0;
    //dir = 0  --> Bottom to Top
    //dir = 1  --> Top to Bottom
    while(count++ < rows*cols) {
        cout << matrix[i][j] << " ";
        if(dir == 0) {
            if(j == cols -1 ) {
                dir = 1;
                i++;
            }
            else if(i == 0) {
                dir = 1;
                j++;
            }
            else {
                i--;
                j++;
            }
        }
        else {
            if(i == rows - 1) {
                dir = 0;
                j++;
            }
            else if(j == 0) {
                dir = 0;
                i++;
            }
            else {
                i++;
                j--;
            }
        }
    }
    return 0;
}