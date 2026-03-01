#include <iostream>
using namespace std;

int linearSearch(int *a, int start, int end, int target) {
    if (start > end) {
        return -1;
    }
    if (a[start] == target) {
        return start;
    }
    return linearSearch(a, start + 1, end, target);
}

int main() {
    int n;
    cin >> n;

    int a[20];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int target;
    cin >> target;

    int result = linearSearch(a, 0, n - 1, target);

    if (result != -1)
        cout << result << endl;
    else
        cout << 0 << endl;

    return 0;
}