#include <bits/stdc++.h>
using namespace std;

string PostfixToInfix(string s){

    stack<string> st;

    int n = s.size();

    for(int i = n - 1; i >= 0; i--){

        // operand
        if ((s[i] >= 'A' && s[i] <= 'Z') ||
            (s[i] >= 'a' && s[i] <= 'z') ||
            (s[i] >= '0' && s[i] <= '9')){
            
            st.push(string(1, s[i]));  // convert char → string
        }

        //operator(+,-,*,/,etc..) 
        else{

            //store last 2 element before operator
            string t1 = st.top(); st.pop();
            string t2 = st.top(); st.pop();

            // covert postfix to Prefix ab+ = +ab
            string converter = t1 + t2 = s[i]; // s[i] is operator here

            st.push(converter);
        } 
    }

    return st.top();
}