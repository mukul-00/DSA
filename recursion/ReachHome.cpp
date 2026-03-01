#include <bits/stdc++.h>
using namespace std;

void reachHome(int dest, int src) {

    cout << "Source: " << src << " Destination: " << dest << endl;

    // base case
    if (src == dest) {
        cout << "Pahuch gaye 🏠" << endl;
        return;
    }

    // processing
    src++;

    // recursive call
    reachHome(dest, src);
}

int main() {
    int dest = 10;
    int src = 1;

    reachHome(dest, src);
    return 0;
}
