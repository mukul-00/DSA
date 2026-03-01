#include <bits/stdc++.h>
using namespace std;

int countDistinctWayToClimbStairs(int n) {

    // base cases
    if (n < 0)
        return 0;

    if (n == 0)
        return 1;

    // recursive relation
    return countDistinctWayToClimbStairs(n - 1) +
           countDistinctWayToClimbStairs(n - 2);
}

int main() {
    int n;
    cin >> n;

    cout << countDistinctWayToClimbStairs(n) << endl;
    return 0;
}
