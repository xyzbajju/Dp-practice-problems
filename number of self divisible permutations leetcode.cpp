// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;


int uitl(int n ){
	vector<int>dp(1<<n , 0);
	dp[0] = 1;


	for(int mask = 0; mask < (1<<n); mask++){
		int ct= __builtin_popcount(mask);
		for(int i=0; i< n ;i++){
			if(!(mask & (1<<i))){
				if(((ct+1)%(i+1) == 0) || ((i+1)%(ct+1) == 0)){
					dp[mask | (1<<i)]+=dp[mask];
				}
			}
		}
	}

	return dp[(1<<n)-1];
}

int main() {
int n ;
cin>>n;

cout<<uitl(n)<<endl;
}
