//
// Created by Nguyen Quang Phu on 8/10/2022.
//
#include <bits/stdc++.h>
#define all(a) (a).begin(), (a).end()
#define pb push_back
#define fi first
#define se second
#define mp make_pair
using namespace std;

typedef long long ll;
typedef pair<int, int> II;

void solve() {
    int n; cin >> n;
    vector<vector<int>> a(n);
    for (int i = 0; i < n - 1; ++i) {
        int m; cin >> m;
        for (int j = 0; j < m; ++j) {
            int x; cin >> x;--x;
            a[i].pb(x);
        }
    }
    for (int i = 0; i < n; ++i)
        sort(all(a[i]));
    // bfs
    vector<int> vis(n, 0), pre(n);
    queue<int> qu;
    qu.push(0), vis[0] = 1; pre[0] = -1;
    while (!qu.empty()) {
        int u = qu.front();
        qu.pop();
        if (u == n - 1) {
            vector<int> ans;
            while (1) {
                ans.pb(u);
                u = pre[u];
                if (u == -1)
                    break;
            }
            reverse(all(ans));
            cout << ans.size() - 1 << '\n';
            for (int i = 0; i < ans.size() - 1; ++i)
                cout << ans[i] + 1 << ' ';
            cout << "\n\n";
            return;
        }
        for (int v: a[u]) {
            if (!vis[v]) {
                vis[v] = 1;
                pre[v] = u;
                qu.push(v);
            }
        }
    }
    cout << "-1\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("E:\\cp-clion\\input.inp", "r", stdin);
#endif

    int tt; cin >> tt;
    while (tt--) {
        solve();
    }

	return 0;
}