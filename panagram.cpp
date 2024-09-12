#include<bits/stdc++.h>
using namespace std;
int main() {
    string s;
    cout << "Enter the String : ";
    getline(cin,s);
    vector<bool> arr(26,false);
    for(int i = 0; i < s.length(); i++) {
        int ascii = s[i];
        // For Upper Case
        if(ascii >= 65 && ascii <= 90) {
            arr[ascii - 'A'] = true;
        }
        //For Lower Case
        if(ascii >= 97 && ascii <= 122) {
            arr[ascii - 'a'] = true;
        }
    }
    bool check = false;
    for(int i = 0; i < 26; i++) {
        if(arr[i] == false) {
            check = true;
            cout << char(i + 'a') << " ";
        }
    }
    if(check == false) {
        cout << "The given string is a pangram";
    }
    return 0;
}