#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    vector<int> brr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> brr[i];
    }
    int cost;
    cin >> cost;
    int f = 0;
    int g = INT_MAX;
    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
        int regularCost = arr[i];
        int expressCost = brr[i];

        int newRegular = min(regularCost + f, expressCost + g);
        int newExpress = min(f + expressCost + cost, expressCost + g);

        f = newRegular;
        g = newExpress;

        ans[i] = min(f, g);
    }

    for (auto it : ans) {
        cout << it << " ";
    }
    cout << endl;
    return 0;
}
