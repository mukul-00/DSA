#include <bits/stdc++.h>
#include <stack>
using namespace std;

// priority function
int priority(char ch) {
    if (ch == '^') return 3;
    if (ch == '*' || ch == '/') return 2;
    if (ch == '+' || ch == '-') return 1;
    return -1;
}

string reverseStr(string s){

    reverse(s.begin(), s.end());

    for(int i = 0; i < s.size(); i++){
        if(s[i] == '(') s[i] = ')';
        else if(s[i] == ')') s[i] = '(';
    }

    return s;
}

string InfixToPrefix(string s){

    s = reverseStr(s);

    stack<char> st;
    string ans;

    int i = 0;

    int n = s.size();

    while(i < n){

        //operand 
        if ((s[i] >= 'A' && s[i] <= 'Z') ||
            (s[i] >= 'a' && s[i] <= 'z') ||
            (s[i] >= '0' && s[i] <= '9')){
            ans += s[i];
        }

        //opening bracket
        else if(s[i] == '('){
            st.push(s[i]);
        }

        //closing bracket
        else if(s[i] == ')'){
            while(!st.empty() && st.top() != '('){
                ans += st.top();
                st.pop();
            }
            st.pop(); // remove '('
        }

        //operator
        else {
            while (!st.empty() && 
                (priority(s[i]) < priority(st.top()) || 
                (priority(s[i]) == priority(st.top()) && s[i] != '^'))){
                ans += st.top();
                st.pop();
            }
            st.push(s[i]);
        }
        i++;
    }

    // remaining elements
    while (!st.empty()){
        ans += st.top();
        st.pop();
    }

    ans = reverseStr(ans);
    return ans;
}


int main() {
    string s;
    
    cout << "Enter infix expression: ";
    cin >> s;

    string result = InfixToPrefix(s);

    cout << "Prefix expression: " << result << endl;

    return 0;
}