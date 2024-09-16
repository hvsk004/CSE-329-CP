#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<vector<int>> matrix = {{1, 2, 3, 4}, {4, 1, 3, 2}, {5, 4, 2, 1}, {1, 2, 4, 3}};
    int m = matrix.size();
    int n = matrix[0].size();
    vector<bool> ans(n, true);
    for (int i = 1; i < m; i++)
    {
        unordered_set<int> s(matrix[i].begin(), matrix[i].end());
        for (int i = 0; i < n; i++)
        {
            int x = matrix[0][i];
            if (s.find(x) == s.end())
            {
                ans[i] = false;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (ans[i])
        {
            cout << matrix[0][i] << " ";
        }
    }
    return 0;
}