#include <bits/stdc++.h>
#include <stack>
using namespace std;

stack<int> st;
stack<int> minSt;

void push(int x){
    st.push(x);

    if(minSt.size() == 0 || minSt.top() >= x){
        minSt.push(x);
        return;
    } 

}

int pop(){
    if(st.size() == 0) return -1;

    int ans = st.top();
    st.pop();

    if(minSt.top() == ans){
        minSt.pop();
    }

    return ans;
}

int top(){
    if(st.empty()){
        return -1;
    }
    return st.top();
    

}

int getMin(){
    if(minSt.size() == 0) return -1;
    return minSt.top();
}

int main() {
    push(5);
    push(3);
    push(7);
    push(2);

    cout << "Current Min: " << getMin() << endl; // 2

    cout << "Top Element: " << top() << endl; // 2

    cout << "Popped: " << pop() << endl; // removes 2

    cout << "Current Min: " << getMin() << endl; // 3

    cout << "Popped: " << pop() << endl; // removes 7

    cout << "Top Element: " << top() << endl; // 3

    cout << "Current Min: " << getMin() << endl; // 3

    return 0;
}