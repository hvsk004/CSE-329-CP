#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    vector<int> candies(n, 1);

    // Left to right pass
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > arr[i - 1])
        {
            candies[i] = candies[i - 1] + 1;
        }
    }

    // Right to left pass
    for (int i = n - 2; i >= 0; i--)
    {
        if (arr[i] > arr[i + 1])
        {
            candies[i] = max(candies[i], candies[i + 1] + 1);
        }
    }

    int sum = accumulate(candies.begin(), candies.end(), 0);

    cout << "Candies Distribution:\n";
    for (int i = 0; i < n; i++)
    {
        cout << "Child " << i + 1 << " (Rating: " << arr[i] << ") gets " << candies[i] << " candies\n";
    }
    cout << "Total number of candies distributed: " << sum << endl;

    return 0;
}
