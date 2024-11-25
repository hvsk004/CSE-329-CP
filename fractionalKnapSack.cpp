#include <bits/stdc++.h>
using namespace std;

struct Item
{
    int weight, value;
    double valuePerWeight;
};

bool compare(Item &a, Item &b)
{
    return a.valuePerWeight > b.valuePerWeight;
}

double solve(vector<int> &wts, vector<int> &vals, int capacity)
{
    int n = wts.size();
    vector<Item> items(n);
    for (int i = 0; i < n; i++)
    {
        items[i] = {wts[i], vals[i], (double)vals[i] / wts[i]};
    }

    sort(items.begin(), items.end(), compare);

    double ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (items[i].weight <= capacity)
        {
            ans += items[i].value;
            capacity -= items[i].weight;
        }
        else
        {
            ans += items[i].valuePerWeight * capacity;
            break;
        }
    }
    return ans;
}

int main()
{
    int n;
    cout << "Enter the number of items: ";
    cin >> n;
    vector<int> wts(n);
    vector<int> vals(n);
    for (int i = 0; i < n; i++)
    {
        cout << "Enter the weight and value of item " << i + 1 << ": ";
        cin >> wts[i] >> vals[i];
    }
    int capacity;
    cout << "Enter the capacity of the knapsack: ";
    cin >> capacity;
    cout << "Maximum value that can be obtained: " << solve(wts, vals, capacity) << endl;
    return 0;
}
