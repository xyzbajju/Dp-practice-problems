#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dp[1001][1001];
    vector<pair<int,int>> del = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

    bool isSafe(int i, int j, vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        return (i >= 0 && j >= 0 && i < n && j < m);
    }

    int dfs(int i, int j, vector<vector<int>>& grid) {
        if (dp[i][j] != -1) return dp[i][j];

        int ans = 1; 
        for (auto [di, dj] : del) {
            int newi = i + di;
            int newj = j + dj;
            if (isSafe(newi, newj, grid) && grid[newi][newj] < grid[i][j]) {
                ans = (ans + dfs(newi, newj, grid)) % 1000000007; 
            }
        }

        return dp[i][j] = ans;
    }

    int countPaths(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        memset(dp, -1, sizeof(dp));

        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ans = (ans + dfs(i, j, grid)) % 1000000007;
            }
        }

        return ans;
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    Solution sol;
    cout << sol.countPaths(grid) << endl;

    for(int i=0;i<n;i++){
        for(int j =0;j<m;j++){
            cout<<sol.dp[i][j]<<" ";
        }cout<<endl;
    }cout<<endl;
}
