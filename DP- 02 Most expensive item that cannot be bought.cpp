// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

int main() {
int a , b;
cin>>a>>b;
int x = a*b;

int res = 0;
vector<bool>dp(x+1 , 0);
for(int i = 1; i  < x ;i++){
	if(i % a  ==0 || i%b == 0 ){
		dp[i ] = true;
	}

	if(dp[i] && i+a <= x)dp[i+a] = true;
	if(dp[i] && i+b <= x)dp[i+b] = true;

}


for(int i= 1; i<=x  ;i++){
	if(!dp[i]){
		res = i ;
		break;
	}
}


cout<<res<< endl;
}
