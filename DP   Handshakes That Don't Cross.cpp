#include <bits/stdc++.h>
using namespace std;
 vector<int>dp(100000+1,0);
int util(int N) {

       dp[0]=1;
       
       for(int n=2;n<=N;n+=2)
       {
           for(int i=0;i<=n-2;i+=2)
           {
               dp[n]+=dp[i]*dp[n-2-i];
           }
           
       }
       
       return dp[N];
}

int main() {
    int n;
    cin >> n;
     
    int ans = util(n); 
    cout << ans << endl;
    return 0;
}
