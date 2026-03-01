#include <bits/stdc++.h>
using namespace std;

string addBinary(string a, string b) {
    string ans = "";
    int carry = 0;

    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());  // reverse strings

    int n = max(a.length(), b.length());

    int digit1, digit2;
    for (int i = 0; i < n; i++) {

        if(i < a.length()){
            digit1 = a[i] - '0';// char -> int
        }
        else{
            digit1 = 0;
        }

        if(i < b.length()){
            digit2 = b[i] - '0';
        }
        else{
            digit2 = 0;
        }
        int total = digit1 + digit2 + carry;

        ans = char((total % 2) + '0') + ans;  // current bit
        carry = total / 2;                   // carry
    }

    if (carry == 1) {
        ans = '1' + ans;  // leftover carry
    }

    return ans;
}

int main() {
    string a = "11";
    string b = "01";

    string res = addBinary(a, b);
    cout << res << endl;

    return 0;
}

// string addBinary(string a, string b) {
//     int i = a.length() - 1;
//     int j = b.length() - 1;
//     int carry = 0;

//     string ans = "";

//     while (i >= 0 || j >= 0 || carry) {
//         int sum = carry;

//         if (i >= 0) {
//             sum += a[i] - '0';  // convert '0'/'1' → 0/1
//             i--;
//         }

//         if (j >= 0) {
//             sum += b[j] - '0';
//             j--;
//         }

//         char ch = sum % 2 + '0';
//         ans = ch + ans;
//         carry = sum / 2;
//     }

//     return ans;
// }
