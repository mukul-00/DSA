// #include <bits/stdc++.h>
// #include <utility>
// using namespace std;

// int partition(int *arr, int s, int e){
//     int pivot = arr[s]; 

//     int count = 0;
//     for(int i = s+1; i <= e; i++){
//         if(arr[i] < pivot){
//             count++;
//         }
//     }

//     // place pivot at right postion 
//     // ✅ Why s + count ?
//     // Because-> s = starting index of current subarray
//     // count = how many numbers should be BEFORE pivot 
//     int pivotIndex = s + count;
//     swap(arr[pivotIndex], arr[s]);

//     // left and right part sambhal lete hai
//     int i = s;
//     int j = e;

//     while(i < pivotIndex && j > pivotIndex){

//         while(arr[i] <pivot){
//             i++;
//         }
//         while(arr[j] > pivot){
//             j--;
//         }

//         if(i < pivotIndex && j > pivotIndex){
//             swap(arr[i++], arr[j--]);
//         }
//     }
//     return pivotIndex;

// }
// void quickSort(int *arr, int s, int e){

//     // Base case
//     if(s >= e)
//         return;

//     // Parttition of Array
//     int p = partition(arr, s, e);

//     // Left part sort
//     quickSort(arr, s, p - 1);

//     // Right part sort
//     quickSort(arr, p + 1, e);
// }

 
// int main(){
//     int arr[5] = {2,4,1,6,9};
//     int n = 5;

//     quickSort(arr, 0, n - 1);

//     for(int i = 0; i < n; i++){
//         cout << arr[i] << " ";
//     }
//     cout << endl;

//     return 0;
// }

// explanation
// https://chatgpt.com/s/t_6987375bf1a48191acd0a90fff4ad095 (for s + count)
// https://chatgpt.com/share/699de03c-613c-8004-a2f9-60c171c5549b (for while loop)


#include <bits/stdc++.h>
using namespace std;

// Partition function: places pivot at correct position
int partition(int arr[], int low, int high) {
    int pivot = arr[high];   // choose last element as pivot
    int i = low - 1;         // index of smaller element

    for(int j = low; j < high; j++) {
        if(arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);   // swap smaller element to left
        }
    }

    swap(arr[i + 1], arr[high]);   // place pivot in correct position
    return i + 1;
}

// QuickSort function
void quickSort(int arr[], int low, int high) {
    if(low >= high) return;   // base case

    int p = partition(arr, low, high);  // get pivot index

    quickSort(arr, low, p - 1);   // sort left part
    quickSort(arr, p + 1, high);  // sort right part
}

int main() {
    int arr[] = {4, 1, 3, 2, 5};
    int n = 5;

    quickSort(arr, 0, n - 1);

    // print sorted array
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}