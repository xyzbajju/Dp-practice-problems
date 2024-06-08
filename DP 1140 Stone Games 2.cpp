#include <bits/stdc++.h>
#include <climits>
using namespace std;

int dp[2][101][101];
vector<int> pre;

void prev(vector<int>& piles) {
    int n = piles.size();
    pre.resize(n);
    pre[0] = piles[0];
    for (int i = 1; i < n; i++) {
        pre[i] = pre[i - 1] + piles[i];
    }
}

int util(int isAlice, int ind, int m, vector<int>& piles, int n) {
    if (ind == n) return 0;
    if (dp[isAlice][ind][m] != -1) return dp[isAlice][ind][m];
    
    int stones = isAlice ? INT_MIN : INT_MAX;

    for (int i = 1; i <= min(2 * m, n - ind); i++) {
        if (isAlice) {
            int x = pre[ind + i - 1] - (ind > 0 ? pre[ind - 1] : 0);
            stones = max(stones, x + util(0, ind + i, max(i, m), piles, n));
        } else {
            stones = min(stones, util(1, ind + i, max(i, m), piles, n));
        }
    }
    return dp[isAlice][ind][m] = stones;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    memset(dp, -1, sizeof(dp));
    prev(arr); 

    cout << util(1, 0, 1, arr, n) << endl;

    return 0;
}
