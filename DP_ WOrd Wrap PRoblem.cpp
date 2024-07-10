// Source: https://usaco.guide/general/io


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
int dp[505][2005];

                //   Memoization Approach   //
////////////////////////////////////////////////////////

int util(int ind, int used, vector<int>& nums, int k) {
    if (ind == nums.size()) return 0;

    if (dp[ind][used] != -1) return dp[ind][used];

    int a = INT_MAX, b = INT_MAX;
    // If we stay on the same line;
    if (used + nums[ind] + 1 <= k) {
        a = util(ind + 1, used + nums[ind] + 1, nums, k);
    }
    // If we change the line
    b = (k - used) * (k - used) + util(ind + 1, nums[ind], nums, k);
    return dp[ind][used] = min(a, b);
}

int solveWordWrap(vector<int> nums, int k) {
    // memset(dp, -1, sizeof(dp));
    // return util(1, nums[0], nums, k);
    
 
                    //   Tabulation Approach    //
////////////////////////////////////////////////////////////////

    int n= nums.size();
    memset(dp , INT_MAX ,sizeof(dp));
    for (int j = 0; j <= k; ++j) {
        dp[n][j] = 0;
    }
    for(int i= n-1; i>=0;i--){
        for(int used = k ; used>=0 ; used--){
             int a = INT_MAX, b = INT_MAX;
             if(used + nums[i] + 1<= k)a = dp[i+1][used + nums[i] + 1];
             
            b = (k - used) * (k - used) + dp[i + 1][nums[i]];
            
            dp[i][used] = min(a , b);
        }
    }
    return dp[1][nums[0]];
}
};


int main() {
	int n;
	cin>>n;
	vector<int>arr(n);
	for(int i=0;i<n;i++){cin>>arr[i];}
	int k;
	cin>>k;
     Solution Harsh;
	int ans = Harsh.solveWordWrap(arr , k);
	cout<<ans<<endl;

}
