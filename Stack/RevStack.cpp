#include <bits/stdc++.h>
using namespace std;

// insert element at bottom of stack
void insertAtBottom(stack<int> &st, int element){
    
    // base case: if stack is empty, push element
    if(st.empty()){
        st.push(element);
        return;
    }

    // store top element
    int n = st.top();
    st.pop();
    
    // recursive call to reach bottom
    insertAtBottom(st, element);

    // backtracking: put stored element back
    st.push(n);
}


// reverse the stack using recursion
void reverseStack(stack<int> &stack){

    // base case: if empty, nothing to reverse
    if(stack.empty()){
        return;
    }

    // store top element
    int num = stack.top();
    stack.pop();

    // reverse remaining stack
    reverseStack(stack);

    // insert stored element at bottom
    insertAtBottom(stack, num);
}


// (imp) hum bs ek case solve krte hai recursion mein toh humko ek case leke hi sochna hai

// Now let’s dry run properly 


// # Example Stack
// Top → 3 2 1

// # 🪜 Step 1: reverseStack() calls

// reverseStack([1,2,3])

// → pop 3
// → reverseStack([1,2])

// → pop 2
// → reverseStack([1])

// → pop 1
// → reverseStack([])


// Now stack is empty ✅

// 🔄 Step 2: Backtracking (THIS is where reverse happens)

// 👉 Insert 1 at bottom

// stack = [1]

//  👉 Insert 2 at bottom

// Call:

// insertAtBottom([1], 2)

// Steps:

// * pop 1
// * stack empty → push 2
// * push back 1


// stack = [2, 1]

// 👉 Insert 3 at bottom

// Call:

// insertAtBottom([2,1], 3)


// Steps:

// * pop 1
// * pop 2
// * empty → push 3
// * push back 2
// * push back 1

// stack = [3, 2, 1]



// # 🧠 Key Idea (VERY IMPORTANT)

// ### reverseStack():

// * Removes all elements

// ### insertAtBottom():

// * Puts each element **at bottom instead of top**


