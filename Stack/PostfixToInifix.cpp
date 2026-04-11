#include <bits/stdc++.h>
using namespace std;

string PostfixToInfix(string s){

    stack<string> st;

    int n = s.size();

    for(int i = 0; i < n; i++){

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

            // covert postfix to infix ab+ = a+b
            string converter = "(" + t2 + s[i] + t1 + ")"; // s = ab+de- , this converter is doing (a+b), (d-e)

            st.push(converter);
        } 
    }

    return st.top();
}