#include <bits/stdc++.h>
#include <utility>
#include <vector>
using namespace std;

vector<int> NSL(vector<int>& arr){
    vector<int> Left;
    stack<pair<int, int>> st;

    int n = arr.size();

    for(int i = 0; i < n; i++){

        while(st.size() > 0 && st.top().first >= arr[i]){
            st.pop();
        }
        if(st.size() == 0){
            Left.push_back(-1);
        }
        else{
            Left.push_back(st.top().second);
        }
        st.push({arr[i], i});
    }
    return Left;
}

vector<int> NSR(vector<int>& arr){
    vector<int> Right;
    stack<pair<int, int>> st;

    int n = arr.size();

    for(int i = n - 1; i >= 0; i--){

        while(st.size() > 0 && st.top().first >= arr[i]){
            st.pop();
        }
        if(st.size() == 0){
            Right.push_back(n);
        }
        else{
            Right.push_back(st.top().second);
        }
        st.push({arr[i], i});
    }
    reverse(Right.begin(), Right.end());
    return Right;
}

int getMaxArea(vector<int> &arr){

    vector<int> left = NSL(arr);
    vector<int> right = NSR(arr);

    int maxArea = 0;

    for(int i = 0; i < arr.size(); i++){
        int width = right[i] - left[i] - 1;
        int area = arr[i] * width;

        maxArea = max(maxArea, area);
    }

    return maxArea;
    
}

int main() {
    vector<int> arr = {60, 20, 50, 40, 10, 50, 60};
    cout << getMaxArea(arr) << endl;
    return 0;
}