#include <iostream>
using namespace std;

// Merge two sorted parts
void merge(int *arr, int s, int e) {

    int mid = (s + e) / 2;

    int len1 = mid - s + 1;
    int len2 = e - mid;

    int *first = new int[len1];
    int *second = new int[len2];

    // copy left
    int k = s; // k is main array index
    for(int i = 0; i < len1; i++)
        first[i] = arr[k++];

    // copy right
    k = mid + 1;
    for(int i = 0; i < len2; i++)
        second[i] = arr[k++];

    // merge
    int index1 = 0, index2 = 0;
    k = s;
    while(index1 < len1 && index2 < len2) {
        if(first[index1] < second[index2])
            arr[k++] = first[index1++];
        else
            arr[k++] = second[index2++];
    }

    // remaining left
    while(index1 < len1)
        arr[k++] = first[index1++];

    // remaining right
    while(index2 < len2)
        arr[k++] = second[index2++];

    delete[] first;
    delete[] second;
}

void sortArr(int *arr, int s, int e) {

    if(s >= e) return;

    int mid = (s + e) / 2;

    sortArr(arr, s, mid);
    sortArr(arr, mid + 1, e);

    merge(arr, s, e);
}

int main() {

    int arr[15] = {3,7,0,1,5,8,3,2,34,66,87,23,12,12,12};
    int n = 15;

    sortArr(arr, 0, n - 1);

    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}
