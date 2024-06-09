// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;


    int dp[1005][1005];

    int ascii(char c) {
        return int(c);
    }

    int util(int i, int j, int del1, int del2, string s1, string s2) {
        int n = s1.length();
        int m = s2.length();
        if (i == n) {
            int x = n - del1;
            int y = m - del2;
            int z = y - x;
            int sum = 0;
            for (int i = m - 1; i >= 0 && z > 0; i--, z--) {
                sum += ascii(s2[i]);
            }
            return sum;
        }
        if (j == m) {
            int x = n - del1;
            int y = m - del2;
            int z = x - y;
            int sum = 0;
            for (int i = n - 1; i >= 0 && z > 0; i--, z--) {
                sum += ascii(s1[i]);
            }
            return sum;
        }
        if (dp[i][j] != -1) return dp[i][j];
        int x = INT_MAX;
        if (s1[i] == s2[j]) {
            return util(i + 1, j + 1, del1, del2, s1, s2);
        } else {
            x = min(ascii(s1[i]) + util(i + 1, j, del1 + 1, del2, s1, s2),
                    ascii(s2[j]) + util(i, j + 1, del1, del2 + 1, s1, s2));
        }
        return dp[i][j] = x;
    }

    int minimumDeleteSum(string s1, string s2) {
        int n = s1.length();
        int m = s2.length();
        memset(dp, -1, sizeof(dp));
        return util(0, 0, 0, 0, s1, s2);
    }



int main() {
	string s1 , s2;
    cin>>s1>>s2;
     cout<<minimumDeleteSum(s1 , s2);
} 
