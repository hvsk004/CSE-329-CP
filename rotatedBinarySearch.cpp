#include <bits/stdc++.h>
using namespace std;

int rotatedBinarySearch(vector<int> &nums, int target)
{
    int low = 0, high = nums.size() - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (nums[mid] == target)
            return mid;

        // Determine if the left half is sorted
        if (nums[low] <= nums[mid])
        {
            // Target lies in the sorted left half
            if (nums[low] <= target && target < nums[mid])
                high = mid - 1;
            else
                low = mid + 1;
        }
        else
        {
            // Target lies in the sorted right half
            if (nums[mid] < target && target <= nums[high])
                low = mid + 1;
            else
                high = mid - 1;
        }
    }

    return -1; // Target not found
}

int main()
{
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    cout << "Enter the elements: ";
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    int target;
    cout << "Enter the target: ";
    cin >> target;
    int ans = rotatedBinarySearch(nums, target);
    if (ans == -1)
    {
        cout << "Element not found.";
    }
    else
    {
        cout << "The element is found at index: " << ans;
    }
    return 0;
}
