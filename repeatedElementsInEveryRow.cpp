#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<vector<int>> matrix = {{1, 2, 3, 4}, {5, 2, 1, 4}, {7, 8, 1, 2}};
    int m = matrix.size();
    int n = matrix[0].size();
    vector<int> ans(n, 1);
    for (int k = 0; k < n; k++)
    {
        int a = matrix[0][k];
        for (int i = 1; i < m; i++)
        {
            bool found = false;
            for (int j = 0; j < n; j++)
            {
                if (matrix[i][j] == a)
                {
                    found = true;
                    break;
                }
            }
            if (found == false)
            {
                ans[k] = 0;
                break;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (ans[i] == 1)
        {
            cout << matrix[0][i] << " ";
        }
    }
    return 0;
}