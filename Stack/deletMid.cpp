#include <bits/stdc++.h>
#include <stack>
using namespace std;

void solve(stack<int> &st, int count, int size){

    //base case
    if(count == size/2){
        st.pop();
        return;
    }

    // store the top value 
    int num = st.top();
    st.pop(); // store kiya phir pop kia

    //recursive call
    solve(st, count + 1, size);

    // After middle is removed
    // Push elements back again
    st.push(num);
}

void  deletMid(stack<int> &st, int n){
    int count = 0;
    solve(st, count, n);
}