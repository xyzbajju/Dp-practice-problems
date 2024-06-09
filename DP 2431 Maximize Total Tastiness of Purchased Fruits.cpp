// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;
int dp[105][100005][5];

int util(int ind, int left ,int coupon , vector<int>&price , vector<int>&tastiness ){
   int n = price.size();
	if(ind == n)return 0;
	if(dp[ind][left][coupon]!=-1)return dp[ind][left][coupon];
    
	int x = util(ind+1 , left , coupon , price , tastiness);

	if(price[ind] <= left){
		x = max(x ,tastiness[ind] + util(ind+1 , left-price[ind] ,  coupon , price , tastiness));
	}
	if((price[ind] / 2) <= left && coupon  > 0){
		x =max(x,  tastiness[ind] + util(ind+1 , left - (price[ind] / 2) , coupon - 1 , price , tastiness));
	}


	return dp[ind][left][coupon] = x;

}




int main() {
 int n  ;
 cin>>n;
 vector<int>price(n), tastiness(n);
 for(int i=0;i<n;i++){cin>>price[i];}
 for(int i=0;i<n;i++){cin>>tastiness [i];}
 int maxAmount ,maxCoupons ;
 cin>>maxAmount;
 cin>>maxCoupons;
 memset(dp , -1 , sizeof(dp));

 cout<< util(0 , maxAmount , maxCoupons , price , tastiness);




}
