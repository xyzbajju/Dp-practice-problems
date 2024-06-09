#include <bits/stdc++.h>
using namespace std;

unordered_map<string, vector<int>> dp;

vector<int> util(string s) {
    if (dp.find(s) != dp.end()) {
        return dp[s];
    }

    vector<int> ans;
    for (int ind = 0; ind < s.length(); ++ind) {
        char curr = s[ind];
        if (curr == '+' || curr == '-' || curr == '*') {
            vector<int> left, right;
            string str1 = s.substr(0, ind);
            string str2 = s.substr(ind + 1);

            if (dp.find(str1) != dp.end()) {
                left = dp[str1];
            } else {
                left = util(str1);
            }

            if (dp.find(str2) != dp.end()) {
                right = dp[str2];
            } else {
                right = util(str2);
            }

            for (auto it : left) {
                for (auto ite : right) {
                    if (curr == '+') ans.push_back(it + ite);
                    else if (curr == '*') ans.push_back(it * ite);
                    else if (curr == '-') ans.push_back(it - ite);
                }
            }
        }
    }


    if (ans.empty()) {
        ans.push_back(stoi(s));
    }

    return dp[s] = ans;
}

int main() {
    string s;
    cin >> s;
    vector<int> results = util(s);
    for (int result : results) {
        cout << result << " ";
    }
    cout << endl;
    return 0;
}
