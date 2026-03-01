#include <bits/stdc++.h>
using namespace std;

bool isValidParenthesis(string expression)
{
  	stack<char> s;
    for(int i=0; i<expression.length(); i++) {
         
        char ch = expression[i];
         
        //if opening bracket, stack push
        //if close bracket, stacktop check and pop
         
        if(ch == '(' || ch == '{' || ch == '['){
            s.push(ch);
        }
        else
        {
            //for closing bracket
            if(!s.empty()) {
                char top = s.top();
                if( (ch == ')' && top == '(') || 
                    ( ch == '}' && top == '{') || 
                    (ch == ']' && top == '[') ) {
                    s.pop();
                }
                else
                {
                    return false;
                }
            }
            else
            {
                return false;
            } 
        }  
    }
    
    if(s.empty())
        return true;
    else
        return false;
}


// #include <stack>
// #include <string>
// using namespace std;

// class Solution {
// public:
//     bool isValid(string s) {
//         stack<char> st;
//         for (char ch : s) {
//             if (ch == '(' || ch == '[' || ch == '{') {
//                 st.push(ch);
//             } 
//             else {
//                 if (st.empty()) {
//                     return false;
//                 }

//                 char top = st.top();
//                 st.pop();
                
//                 if ((ch == ')' && top != '(') ||
//                    (ch == ']' && top != '[') ||
//                    (ch == '}' && top != '{')) {
//                     return false;
//                 }
//             }
//         }
//         return st.empty();
//     }
// };