//
// Created by Nguyen Quang Phu on 8/9/2022.
//
#include <bits/stdc++.h>
#define all(a) (a).begin(), (a).end()
#define pb push_back
#define fi first
#define se second
using namespace std;

typedef long long ll;
typedef pair<int, int> II;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

    int n, m, s, f; cin >> n >> m >> s >> f;
    vector<vector<int>> g(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v; cin >> u >> v;
        g[u].pb(v);
    }
    for (int i = 1; i <= n; ++i)
        sort(all(g[i]));
    vector<int> vis(n + 1, 0), pre(n + 1, 0);
    vis[s] = 1;
    queue<int> qu;
    qu.push(s);
    while (!qu.empty()) {
        int u = qu.front();
        qu.pop();
        if (u == f) {
            vector<int> ans;
            while (1) {
                ans.pb(u);
                u = pre[u];
                if (u == 0)
                    break;
            }
            reverse(all(ans));
            for (auto v: ans)
                cout << v << ' ';
        }
        for (int v: g[u]) {
            if (vis[v]) continue;
            vis[v] = 1;
            pre[v] = u;
            qu.push(v);
        }
    }

	return 0;
}