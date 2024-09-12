#include<bits/stdc++.h>
using namespace std;
void pushElement(int x, stack<int> &s1, stack<int> &s2) {
    s1.push(x);
}
void popElement(stack<int> &s1, stack<int> &s2) {
    if(s2.empty()) {
        while(!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
    }
    s2.pop();
}
int main() {
    stack<int> s1,s2;
    int n;
    cin >> n;
    for(int i=0;i<n;i++) {
        char ch;
        cin >> ch;
        if(ch == 'p') {
            popElement(s1,s2);
        }
        else {
            int x = ch-'0';
            pushElement(x,s1,s2);
        }
    }
}