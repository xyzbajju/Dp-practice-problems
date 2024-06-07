#include <bits/stdc++.h>
using namespace std;

int dp[2002];
int bajaj[2002][2002];

int buff(int start, int end, vector<int>& arr) {
    if (bajaj[start][end] != -1) return bajaj[start][end];

    int gdc = arr[start];
    for (int i = start + 1; i <= end; ++i) {
        gdc = gcd(arr[i], gdc);
    }

    return bajaj[start][end] = gdc;
}

int util(int end, vector<int>& arr) {
    if (end == 0) return 0; 
    if (dp[end] != -1) return dp[end];

    int x = INT_MAX;
    for (int i = end - 1; i >= 0; --i) {
        if (buff(i, end - 1, arr) > 1) {
            x = min(x, util(i, arr) + 1);
        }
    }

    return dp[end] = x;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    memset(dp, -1, sizeof(dp));
    memset(bajaj, -1, sizeof(bajaj));

    cout << util(n, arr) << endl;
   
}
