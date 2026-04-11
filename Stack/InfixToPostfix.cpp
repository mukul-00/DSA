#include <bits/stdc++.h>
#include <stack>
#include <string>
using namespace std;

// priority function
int priority(char ch) {
    if (ch == '^') return 3;
    if (ch == '*' || ch == '/') return 2;
    if (ch == '+' || ch == '-') return 1;
    return -1;
}

string infixToPostfix(string s){

    string ans;
    stack<char> st;

    int n = s.size();

    for (int i = 0; i < n; i++){

        // operand
        if ((s[i] >= 'A' && s[i] <= 'Z') ||
            (s[i] >= 'a' && s[i] <= 'z') ||
            (s[i] >= '0' && s[i] <= '9')){
            ans += s[i];
        }

        // opening bracket
        else if (s[i] == '('){
            st.push(s[i]);
        }

        // closing bracket
        else if (s[i] == ')'){
            while (!st.empty() && st.top() != '('){
                ans += st.top();
                st.pop();
            }
            st.pop(); // remove '('
        }

        // operators
        else {
            while (!st.empty() && priority(s[i]) <= priority(st.top())){
                ans += st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }

    // remaining elements
    while (!st.empty()){
        ans += st.top();
        st.pop();
    }

    return ans;
}


int main() {
    string s;
    
    cout << "Enter infix expression: ";
    cin >> s;

    string result = infixToPostfix(s);

    cout << "Postfix expression: " << result << endl;

    return 0;
}