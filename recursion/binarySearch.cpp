#include <bits/stdc++.h>
using namespace std;

bool binarySearch(int *arr, int start, int end, int key) {

    // base case
    if (start > end)
        return false;

    int mid = (start + end) / 2;

    if (arr[mid] == key)
        return true;

    if (arr[mid] < key)
        return binarySearch(arr, mid + 1, end, key);
    else
        return binarySearch(arr, start, mid - 1, key);
}

int main() {
    int arr[4] = {1, 2, 5, 7};

    cout << binarySearch(arr, 0, 3, 5) << endl;
    return 0;
}
