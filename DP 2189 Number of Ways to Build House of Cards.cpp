// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;
int dp[501][170];

int util(int i , int j ){
  if(i ==0)return 1;
  if(dp[i][j]!=-1)return dp[i][j];
  int h =1 , used = 2 , ans =0;
  for(; h<=j && used <= i ;h++ , used+=3){
   ans+=util(i - used , h-1);
  }
return dp[i][j] = ans;
}

int main() {
int n;
cin>>n;
memset(dp , -1 , sizeof(dp));

cout<<util(n , n/3 + 1);

}
