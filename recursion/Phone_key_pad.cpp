#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    // Recursive function to build all combinations
    void solve(string digits, string output, int index,
               vector<string> &ans, string mapping[]) {

        // Base case: when we processed all digits
        if (index >= digits.length()) {
            ans.push_back(output);   // store one valid combination
            return;
        }

        // Convert current digit character to number
        int number = digits[index] - '0';

        // Get corresponding letters from mapping
        string value = mapping[number];

        // Try every character for current digit
        for (int i = 0; i < value.length(); i++) {

            output.push_back(value[i]);          // choose one character
            solve(digits, output, index + 1,     // move to next digit
                  ans, mapping);
            output.pop_back();                   // backtrack
        }
    }

    vector<string> letterCombinations(string digits) {

        vector<string> ans;

        // If input is empty, return empty result
        if (digits.length() == 0)
            return ans;

        string output = "";   // temporary string to build combinations
        int index = 0;        // starting index

        // Phone keypad mapping
        string mapping[10] = {
            "", "", "abc", "def", "ghi",
            "jkl", "mno", "pqrs", "tuv", "wxyz"
        };

        // Start recursion
        solve(digits, output, index, ans, mapping);

        return ans;
    }
};

int main() {
    Solution s;

    string digits;
    cout << "Enter digits: ";
    cin >> digits;

    // Get all letter combinations
    vector<string> result = s.letterCombinations(digits);

    cout << "Letter Combinations:\n";
    for (auto &str : result) {
        cout << str << " ";
    }
    cout << endl;

    return 0;
}
