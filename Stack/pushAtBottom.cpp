#include <bits/stdc++.h>
using namespace std;

void solve(stack<int> &s, int x){

    // base case
    if(s.empty()){
        s.push(x);
        return;
    }

    // process (top element in stack num mein store kiye phir pop krdia)
    int num = s.top();
    s.pop();

    // recursive call
    solve(s, x);

    // yha voh num ele store krwae the voh vapas daldiye 
    s.push(num);
}

stack<int> pushAtBottom(stack<int> &myStack, int x){

    solve(myStack, x);
    return myStack;
}

// -----------main-----------------------
// reverse an numbers (not an stack)
void printStack(stack<int> s) {
    // base case
    if(s.empty()) return;

    int num = s.top();
    s.pop();

    // first go deep
    printStack(s);

    // then print
    cout << num << " ";
}

int main() {

    stack<int> st;

    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);

    int x = 5;

    st = pushAtBottom(st, x);

    printStack(st);

    return 0;
}
