//
// Created by Nguyen Quang Phu on 8/12/2022.
//
#include <bits/stdc++.h>
#define all(a) (a).begin(), (a).end()
#define pb push_back
#define fi first
#define se second
#define mp make_pair
using namespace std;

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}

#define dbg(x...) cerr << "[" << #x << "] = ["; _print(x)

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vector<int>> vii;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("E:\\cp-clion\\input.inp", "r", stdin); // custom
#endif

    int n, m;
    cin >> n >> m;
    vector<vector<char>> g(n, vector<char>(m));
    int xs, ys, xf, yf;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> g[i][j];
            if (g[i][j] == 'A')
                xs = i, ys = j;
            if (g[i][j] == 'B')
                xf = i, yf = j;
        }
    }
    vii vis(n, vi(m, 0));
    vector<vector<ii>> trace(n, vector<ii>(m));
    vis[xs][ys] = 1;
    // trace[xs][ys].fi = trace[xs][ys].se = -1;
    queue<ii> qu;
    qu.push(ii(xs, ys));
    const int dx[] = {-1, 0, 0, 1};
    const int dy[] = {0, -1, 1, 0};
    while (!qu.empty()) {
        int u = qu.front().fi;
        int v = qu.front().se;
        qu.pop();
//        dbg(u, v);
        if (u == xf && v == yf) {
            cout << "YES\n";
            vector<ii> ans;
            while (u != xs || v != ys) {
                ans.pb(ii(u, v));
                int t1 = u, t2 = v;
                u = trace[t1][t2].fi, v = trace[t1][t2].se;
            }
            ans.pb(ii(xs, ys));
            cout << ans.size() - 1 << '\n';
            reverse(all(ans));
            string s = "";
            for (int i = 1; i < ans.size(); ++i) {
                if (ans[i].fi - 1 == ans[i - 1].fi) s = s + "D";
                if (ans[i].fi + 1 == ans[i - 1].fi) s = s + "U";
                if (ans[i].se - 1 == ans[i - 1].se) s = s + "R";
                if (ans[i].se + 1 == ans[i - 1].se) s = s + "L";
            }
            cout << s << '\n';
            return 0;
        }
        for (int i = 0; i < 4; ++i) {
            int x = u + dx[i];
            int y = v + dy[i];
            if (x < 0 || x >= n || y < 0 || y >= m) continue;
            if (vis[x][y] || g[x][y] == '#') continue;
            vis[x][y] = 1;
            trace[x][y].fi = u, trace[x][y].se = v;
            qu.push(ii(x, y));
        }
    }
    cout << "NO\n";
	return 0;
}
