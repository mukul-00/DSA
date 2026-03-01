#include <bits/stdc++.h>
using namespace std;

void solve(string str, string output, int index, vector<string> &ans){

    // base case: when index reaches end of string
    if(index >= str.length()){
        if(output.length() > 0){
            ans.push_back(output);   // store one subsequence
        }
        return;
    }

    // exclude current character
    solve(str, output, index + 1, ans);

    // include current character
    char element = str[index];
    output.push_back(element);
    solve(str, output, index + 1, ans);
}

vector<string> subsequences(string str){

    vector<string> ans;
    string output = "";
    int index = 0;

    solve(str, output, index, ans);
    return ans;
}

int main(){
    string str;
    cin >> str;   // input string

    vector<string> result = subsequences(str);

    // print all subsequences
    for(auto s : result){
        cout << s << " ";
    }

    return 0;
}
