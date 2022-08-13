//
// Created by Nguyen Quang Phu on 8/11/2022.
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

    int n, m, s; cin >> n >> m >> s;
    vector<vector<ii>> g(n);
    for (int i = 0; i < m; ++i) {
        int u, v, x; cin >> u >> v >> x;
        g[u].pb(ii(v, x));
    }
    vector<bool> vis(n, 0);
    const int inf = 1e9;
    vi d(n, inf);
    d[s] = 0;
    priority_queue<ii, vector<ii>, greater<ii>> qu;
    qu.push(ii(d[s], s));
    while (!qu.empty()) {
        int u = qu.top().se;
        qu.pop();
        if (vis[u]) continue;
        vis[u] = 1;
        for (auto v: g[u]) {
            if (d[v.fi] > d[u] + v.se) {
                d[v.fi] = d[u] + v.se;
                qu.push(ii(d[v.fi], v.fi));
            }
        }
    }

    for (int i: d)
        if (i != inf)
            cout << i << '\n';
        else
            cout << "-1\n";

	return 0;
}
