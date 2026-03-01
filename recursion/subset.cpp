#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
private:
    // Recursive function to generate all subsets
    void solve(vector<int> nums, vector<int> output, int index, vector<vector<int>> &ans){
        
        // Base case: if we have processed all elements
        if(index >= nums.size()){
            ans.push_back(output);   // store the current subset
            return;
        }
        
        // Case 1: Exclude the current element
        solve(nums, output, index + 1, ans);

        // Case 2: Include the current element
        int element = nums[index];
        output.push_back(element);   // add current element to subset
        solve(nums, output, index + 1, ans);
    }

public:
    vector<vector<int>> subsets(vector<int>& nums) {

        vector<vector<int>> ans;   // stores all subsets
        vector<int> output;        // current subset being built
        int index = 0;             // start from first element

        solve(nums, output, index, ans);

        return ans;                // return all generated subsets
    }
};


int main() {
    Solution s;

    vector<int> nums = {1, 2, 3};
    vector<vector<int>> result = s.subsets(nums);

    cout << "[";

    for (int i = 0; i < result.size(); i++) {
        cout << "[";

        for (int j = 0; j < result[i].size(); j++) {
            cout << result[i][j];
            if (j != result[i].size() - 1)
                cout << ",";
        }

        cout << "]";
        if (i != result.size() - 1)
            cout << ",";
    }

    cout << "]";

    return 0;
}
