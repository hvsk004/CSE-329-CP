#include <bits/stdc++.h>
using namespace std;
int findLargestPrimeFactor(int n)
{
    int maxPrime = -1;
    while (n % 2 == 0)
    {
        maxPrime = 2;
        n >>= 1;
    }
    for (int i = 3; i <= sqrt(n); i += 2)
    {
        while (n % i == 0)
        {
            maxPrime = i;
            n = n / i;
        }
    }
    if (n > 2)
    {
        maxPrime = n;
    }
    return maxPrime;
}
bool checkSmooth(int n, int k)
{
    int maxPrime = findLargestPrimeFactor(n);
    return maxPrime <= k;
}
int main()
{
    int i = 2;
    int p, limit;
    cout << "Enter the value of p: ";
    cin >> p;
    cout << "Enter the value of limit: ";
    cin >> limit;
    int count = 0;
    vector<int> smoothNumbers;
    while (count < limit)
    {
        if (checkSmooth(i, p))
        {
            smoothNumbers.push_back(i);
            cout << i << " ";
            count++;
        }
        i++;
    }
    return 0;
}