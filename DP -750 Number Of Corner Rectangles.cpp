#include <bits/stdc++.h>
using namespace std;
int n = 1000;
int m = 1000;

int main() {
    vector<vector<int>> grid(n, vector<int>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    int ans = 0;
    map<pair<int, int>, int> mp;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 1) {
                for (int k = j + 1; k < m; k++) {
                    if (grid[i][k] == 1) {
                        mp[{j, k}]++;
                    }
                }
            }
        }
    }

    for (auto it : mp) {
        ans += ((it.second - 1) * (it.second)) / 2;
    }

    cout << ans << endl;

    return 0;
}
