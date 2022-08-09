//
// Created by Nguyen Quang Phu on 8/8/2022.
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

    int n, m; cin >> n >> m;
    vector<vector<char>> g(n, vector<char>(m));
    int iS, jS, iF, jF;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) {
            cin >> g[i][j];
            if (g[i][j] == 'B')
                iF = i, jF = j;
            if (g[i][j] == 'C')
                iS = i, jS = j;
        }
    vector<vector<int>> vis(n, vector<int>(m, 0));
    vis[iS][jS] = 1;
    queue<II> qu;
    qu.push(II(iS, jS));
    const int dx[] = {-1, 0, 0, 1};
    const int dy[] = {0, -1, 1, 0};
    vector<vector<II>> pre(n, vector<II>(m));
    pre[iS][jS] = II(-1, -1);
    while (!qu.empty()) {
        int u = qu.front().fi;
        int v = qu.front().se;
        qu.pop();
        if (u == iF && v == jF) {
            int ans = 0;
            while (1) {
                ans++;
                int x = pre[u][v].fi;
                int y = pre[u][v].se;
                u = x, v = y;
                if (u == -1 && v == -1)
                    break;
            }
            cout << ans - 1 << '\n';
            return 0;
        }
        for (int i = 0; i < 4; ++i) {
            int x = u + dx[i];
            int y = v + dy[i];
            if (x < 0 || x >= n || y < 0 || y >= m || vis[x][y] || g[x][y] == '*')
                continue;
            vis[x][y] = 1;
            qu.push(II(x, y));
            pre[x][y].fi = u;
            pre[x][y].se = v;
        }
    }

	return 0;
}
