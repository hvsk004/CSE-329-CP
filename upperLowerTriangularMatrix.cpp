#include<bits/stdc++.h>
using namespace std;
void printUpperTriangularMatrix(vector<vector<int>> matrix,int m, int n) {
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(i <= j) {
                cout << matrix[i][j] << " ";
            }
        }
        cout << endl;
    }
}
void printLowerTriangularMatrix(vector<vector<int>> matrix,int m, int n) {
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(i >= j) {
                cout << matrix[i][j] << " ";
            }
        }
        cout << endl;
    }
}
int main() {
    vector<vector<int>> matrix = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
    int m = matrix.size();
    int n = matrix[0].size();
    printUpperTriangularMatrix(matrix,m,n);
    printLowerTriangularMatrix(matrix,m,n);
    return  0;
}