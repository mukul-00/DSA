#include <bits/stdc++.h>
#include <stack>
#include <vector>
using namespace std;

vector<int> calSpan(vector<int> v){

    int n = v.size();

    vector<int> span(n); //empty vector to store indices(result)
    stack<int> st;

    //traverse from Right -> left
    for(int i = 0; i < n; i++){

        while(st.size() > 0 && v[st.top()] <= v[i]){
            st.pop();
        }
        if(st.size() == 0){
            span[i] = i + 1;
        }
        else{
            span[i] = i - st.top();
        }
        st.push(i);
    }
    return span;
}


int main() {
    vector<int> arr = {10, 4, 5, 90, 120, 80};
    vector<int> span = calSpan(arr);
     for (int x : span) {
        cout << x << " ";
    }
    return 0;
}