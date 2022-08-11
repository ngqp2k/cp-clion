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
#ifndef ONLINE_JUDGE
    freopen("E:\\cp-clion\\input.inp", "r", stdin);
#endif
    int n, m, s; cin >> n >> m >> s;
    vector<vector<int>> g(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v; cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    vector<pair<int, int>> ans;
    vector<int> vis(n + 1, 0), d(n + 1);
    vis[s] = 1, d[s] = 0;
    queue<int> qu;
    qu.push(s);
    while (!qu.empty()) {
        int u = qu.front();
        qu.pop();
        ans.pb(make_pair(u, d[u]));
        for (int v: g[u])
            if (!vis[v]) {
                vis[v] = 1;
                d[v] = d[u] + 1;
                qu.push(v);
            }
    }

    auto cmp = [&] (pair<int, int> a, pair<int, int> b) {
        if (a.se != b.se)
            return a.se < b.se;
        else
            return a.fi < b.fi;
    };

    sort(all(ans), cmp);
    for (auto i: ans)
        cout << i.fi << ' ' << i.se << '\n';

	return 0;
}