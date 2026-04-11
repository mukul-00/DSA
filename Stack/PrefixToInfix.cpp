#include <bits/stdc++.h>
#include <stack>
using namespace std;

string PrefixToInfix(string s){

    stack<string> st;

    int n = s.size();

    for(int i = n - 1; i >= 0; i--){

         // operand
        if ((s[i] >= 'A' && s[i] <= 'Z') ||
            (s[i] >= 'a' && s[i] <= 'z') ||
            (s[i] >= '0' && s[i] <= '9'))
        {
            
            st.push(string(1, s[i]));  // convert char → string
        }

        //operator
        else
        {
            string t1 = st.top(); st.pop();
            string t2 = st.top(); st.pop();

            string converter = '(' + t1 + s[i] + t2 + ')'; //s[i] here is operator

            st.push(converter);
        }
    }

    return st.top();
}