#include <bits/stdc++.h>
using namespace std;

bool isSorted(int *arr, int size) {

    // base case
    if (size == 0 || size == 1)
        return true;

    if (arr[0] > arr[1])
        return false;

    // recursive call
    return isSorted(arr + 1, size - 1);
}

int main() {
    int arr[5] = {2, 4, 6, 7, 8};

    if (isSorted(arr, 5))
        cout << "Array is sorted" << endl;
    else
        cout << "Array is not sorted" << endl;

    return 0;
}
