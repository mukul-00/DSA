#include <bits/stdc++.h>
using namespace std;

void reverseString(string &str, int i, int j) {

    // base case
    if (i > j)
        return;

    swap(str[i], str[j]);

    // recursive call
    reverseString(str, i + 1, j - 1);
}

int main() {
    string name = "abcde";

    reverseString(name, 0, name.length() - 1);
    cout << name << endl;

    return 0;
}
