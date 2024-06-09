#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<vector<int>> edges = {
        {0, 1}, {0, 2}, {1, 3}, {1, 4}, {2, 5}
    };
    vector<int> colors = {1, 1, 2, 1, 2, 2};
    int n = edges.size() + 1;
    vector<int> graph[n];
    for (auto it : edges) {
        graph[it[0]].push_back(it[1]);
        graph[it[1]].push_back(it[0]);
    }

    vector<int> size(n);
    int ans = 0;

    function<bool(int, int)> util = [&](int a, int par) {
        bool ok = true;
        size[a] = 1; // Initialize size of current node as 1
        for (int y : graph[a]) {
            if (y != par) {
                bool flag = util(y, a);
                ok = ok && (colors[a] == colors[y]) && flag;
                size[a] += size[y];
            }
        }
        if (ok) {
            ans = max(ans, size[a]);
        }
        return ok;
    };

    util(0, -1);

    cout << ans << endl;
    return 0;
}
