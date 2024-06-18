// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;
int dp[1001][1001];
const int mod = 1e9+7;



int main() {
int n , k;
cin>>n>>k;
memset(dp , 0 , sizeof(dp));

dp[0][0] = 1;

for(int i=1;i<=n;i++){
	for(int j = 1 ; j<=k ; j++){
		 dp[i][j] = (dp[i-1][j-1] + dp[i-1][j] * j )%mod;
	}
}

cout<<dp[n][k]<<endl;

}
