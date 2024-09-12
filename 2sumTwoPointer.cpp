#include<bits/stdc++.h>
using namespace std;
int main() {
    vector<int> nums = {4,2,9,10,6,8};
    int target = 4;
    sort(nums.begin(),nums.end());
    int left = 0, right = nums.size()-1;
    while(left < right) {
        if(nums[left] + nums[right] == target) {
            cout << "The Numbers are : " << nums[left] << " " << nums[right] << endl;
            return 0;
        }
        else if(nums[left] + nums[right] < target) {
            left++;
        }
        else {
            right--;
        }
    }
    cout << "Not Found" << endl;
    return 0;
}