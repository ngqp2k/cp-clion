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

const int mxn = 2e5 + 10;
int n, m;
vi g[mxn];
int d[mxn], vis[mxn], pre[mxn];
int ans[mxn];

void dfs(int u) {
    for (int v: g[u])
        if (!vis[v]) {
            vis[v] = 1;
            d[v] = d[u] + 1;
            pre[v] = u;
            dfs(v);
        }
}

void solve(int u, int v) {
    auto trace = [&] (int x) {
        while (x !=)
    };
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("E:\\cp-clion\\input.inp", "r", stdin); // custom
#endif

    cin >> n >> m;
    for (int i = 0; i < n - 1; ++i) {
        int u, v; cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    for (int i = 0; i < m; ++i) {
        int u, v; cin >> u >> v;
    }
    memset(vis, 0, sizeof vis);
    vis[1] = 1, d[1] = 1, pre[1] = 0;

    dfs(1);

    for (int i = 1; i <= n; ++i)
        cout << d[i] << " ";



	return 0;
}
