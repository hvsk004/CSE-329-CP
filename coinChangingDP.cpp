#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> coins = {2, 5, 7};
    int m = coins.size();
    int n = 9;
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    for (int i = 1; i < n + 1; i++)
    {
        dp[0][i] = INT_MAX - 1;
    }
    for (int i = 1; i < m + 1; i++)
    {
        for (int j = 1; j < n + 1; j++)
        {
            if (coins[i - 1] > j)
            {
                dp[i][j] = dp[i - 1][j];
            }
            else
            {
                dp[i][j] = min(dp[i - 1][j], 1 + dp[i][j - coins[i - 1]]);
            }
        }
    }
    cout << dp[m][n] << endl;
    return 0;
}