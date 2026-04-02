#include <bits/stdc++.h>
using namespace std;

vector<int> nextLargerElement(vector<int> &v) {

    vector<int> res;
    stack<int> st;

    // Traverse from right to left
    int n = v.size();
    for (int i = n - 1; i >= 0; i--) {

        // Remove smaller or equal elements
        while (st.size() > 0 && st.top() <= v[i]) {
            st.pop();
        }

        // Store result using push_back
        if (st.size() == 0) {
            res.push_back(-1);
        } else {
            res.push_back(st.top());
        }

        // Push current element
        st.push(v[i]);
    }

    // Reverse to correct order
    reverse(res.begin(), res.end());

    return res;
}

int main() {
    vector<int> v = {6, 8, 0, 1, 3};

    vector<int> res = nextLargerElement(v);

    for (int x : res) {
        cout << x << " ";
    }

    return 0;
}