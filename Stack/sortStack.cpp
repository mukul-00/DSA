#include <bits/stdc++.h>
using namespace std;

void insertStack(stack<int> &stack, int num){

    // base case
    if(stack.empty() || stack.top() > num){
        stack.push(num);
        return;
    }

    int n = stack.top();
    stack.pop();  

    // recursive call
    insertStack(stack, num);

    // backtracking
    stack.push(n);
}

void sortStack(stack<int> &stack){

    // base case
    if(stack.empty()){
        return;
    }

    int num = stack.top();
    stack.pop();

    // recursive call
    sortStack(stack);

    insertStack(stack, num);
}

int main() {

    stack<int> s;

    // pushing elements
    s.push(3);
    s.push(1);
    s.push(4);
    s.push(2);

    // sort stack
    sortStack(s);

    // print sorted stack
    cout << "Sorted stack (top to bottom): ";
    while(!s.empty()){
        cout << s.top() << " ";
        s.pop();
    }

    return 0;
}
