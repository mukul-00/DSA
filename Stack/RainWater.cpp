#include <iostream>
#include <vector>
using namespace std;

int maxWater(vector<int>& arr) {
    int n = arr.size();

    // left[i] contains height of tallest bar to the
    vector<int> left(n);

    // right[i] contains height of tallest bar to
    vector<int> right(n);

    int water = 0;

    // fill left array
    left[0] = arr[0];
    for (int i = 1; i < n; i++)
        left[i] = max(left[i - 1], arr[i]);

    // fill right array
    right[n - 1] = arr[n - 1];
    for (int i = n - 2; i >= 0; i--)
        right[i] = max(right[i + 1], arr[i]);

    // calculate the accumulated water element by element
    for (int i = 1; i < n - 1; i++) {
        int water = min(left[i], right[i]) - arr[i];
    }

    return water;
}

int main() {
    vector<int> arr = { 2, 1, 5, 3, 1, 0, 4 };
    cout << maxWater(arr);
    return 0;
}


// -------- using Two pointer ---------------

// #include <iostream>
// #include <vector>
// using namespace std;

// int maxWater(vector<int> &arr) { 
//     int left = 1;
//     int right = arr.size() - 2;

//     // lMax : Maximum in subarray arr[0..left-1]
//     // rMax : Maximum in subarray arr[right+1..n-1]
//     int lMax = arr[left - 1];
//     int rMax = arr[right + 1];

//     int res = 0;
//     while (left <= right) {
      
//         // If rMax is smaller, then we can 
//         // decide the amount of water for arr[right]
//         if (rMax <= lMax) {
          
//             // Add the water for arr[right]
//             res += max(0, rMax - arr[right]);

//             // Update right max
//             rMax = max(rMax, arr[right]);

//             // Update right pointer as we have 
//             // decided the amount of water for this
//             right -= 1;
//         } else { 
//             // Add the water for arr[left]
//             res += max(0, lMax - arr[left]);

//             // Update left max
//             lMax = max(lMax, arr[left]);

//             // Update left pointer as we have 
//             // decided water for this
//             left += 1;
//         }
//     }
//     return res;
// }

// int main() {
//     vector<int> arr = {2, 1, 5, 3, 1, 0, 4};
//     cout << maxWater(arr) << endl;
//     return 0;
// }