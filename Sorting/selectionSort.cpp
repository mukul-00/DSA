#include <bits/stdc++.h>
using namespace std;

void selectionSort(vector<int> &arr, int n){
    for(int i = 0; i < n - 1; i++){
        int small = i;  // index of minimum element

        for(int j = i + 1; j < n; j++){
            if(arr[j] < arr[small]){  // compare current element with current minimum
                small = j;
            }
        }

        swap(arr[small], arr[i]);  // place minimum at correct position
    }
}

int main(){
    vector<int> arr = {64, 25, 12, 22, 11};
    
    selectionSort(arr, arr.size());

    for(int x : arr){
        cout << x << " ";
    }
}