#include<bits/stdc++.h>
using namespace std;
void push1(int x, vector<int> &nums, int &top1) {
    if(top1 < nums.size()/2) {
        nums[top1] = x;
        top1++;
    }
    else {
        cout << "Stack Overflow" << endl;
        return;
    }
}
void push2(int x, vector<int> &nums, int &top2) {
    if(top2 < nums.size()) {
        nums[top2] = x;
        top2++;
    }
    else {
        cout << "Stack Overflow" << endl;
        return;
    }
}
int pop1(vector<int> &nums, int &top1) {
    if(top1 > 0) {
        top1--;
        return nums[top1];
    }
    else {
        cout << "Stack Underflow" << endl;
        return -1;
    }
}
int pop2(vector<int> &nums, int &top2) {
    if(top2 > nums.size()/2) {
        top2--;
        return nums[top2];
    }
    else {
        cout << "Stack Underflow" << endl;
        return -1;
    }
}
int main() {
    int n;
    cout << "Enter the length of the array: "; 
    cin >> n;
    vector<int> nums(n);
    int top1 = 0, top2 = n/2;
    while(1) {
        cout << "1. Push in Stack 1" << endl;
        cout << "2. Push in Stack 2" << endl;
        cout << "3. Pop from Stack 1" << endl;
        cout << "4. Pop from Stack 2" << endl;
        cout << "5. Exit" << endl;
        int choice;
        cin >> choice;
        if(choice == 1) {
            int x;
            cout << "Enter the element to be pushed into stack 1 : ";
            cin >> x;
            push1(x,nums,top1);
        }
        else if(choice == 2) {
            cout << "Enter the element to be pushed into stack 2 : ";
            int x;
            cin >> x;
            push2(x,nums,top2);
        }
        else if(choice == 3) {
            cout << "Element poped from stack 1 : " <<pop1(nums,top1) << endl;
        }
        else if(choice == 4) {
            cout << "Element  poped form stack 2: " << pop2(nums,top2) << endl;
        }
        else if(choice == 6) {
            for(int &i : nums) {
                cout << i << " ";
            }
        }
        else {
            break;
        }
    }
    return 0;
}