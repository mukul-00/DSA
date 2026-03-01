#include <bits/stdc++.h>
using namespace std;

void sortArray(int *arr, int n){

    // base case
    if(n == 0 || n == 1){
        return ;
    }

    for(int i = 0; i < n; i++){
        if(arr[i - 1] > arr[i]){
            swap(arr[i - 1], arr[i]);
        }
    }
    sortArray(arr, n - 1);
}

int main(){

    int arr[5] = {1, 4, 2, 6, 3};

    sortArray(arr,5);

    for(int i = 0; i < 5; i++){
        cout << arr[i] << " ";
    }

    return 0;
}