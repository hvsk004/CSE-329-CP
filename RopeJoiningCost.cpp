#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cout << "Enter the value of n: ";
    cin >> n;
    vector<int> ropes(n);
    cout << "Enter the lengths of the ropes: ";
    for (int i = 0; i < n; i++)
    {
        cin >> ropes[i];
    }
    int cost = 0;
    if (n <= 0)
    {
        return 0;
    } 
    while (true)
    {
        if (ropes.size() == 1)
        {
            break;
        }
        sort(ropes.begin(), ropes.end());
        cost += ropes[0] + ropes[1];
        ropes.push_back(ropes[0] + ropes[1]);
        ropes.erase(ropes.begin(), ropes.begin() + 2);
    }
    cout << "The minimum cost of joining the ropes is: " << cost << endl;
    return 0;
}