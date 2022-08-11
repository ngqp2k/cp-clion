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

typedef long long ll;
typedef pair<int, int> II;

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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("E:\\cp-clion\\input.inp", "r", stdin);
#endif

    int n, m, s; cin >> n >> m >> s;
    vector<vector<int>> g(n, vector<int>(n, 0));
    for (int i = 0; i < m; ++i) {
        int u, v, x; cin >> u >> v >> x;
        g[u][v] = x;
    }

    const int inf = 1e9 + 7;

    vector<int> d(n, inf), pre(n);
    d[s] = 0, pre[s] = -1;
    for (int i = 0; i < n; ++i) {
        for (int u = 0; u < n; ++u) {
            for (int v = 0; v < n; ++v) {
                if (g[u][v]) {
                    if (d[u] != inf && d[v] > d[u] + g[u][v]) {
                        d[v] = d[u] + g[u][v];
                        pre[v] = u;
                    }
                }
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int u = 0; u < n; ++u) {
            for (int v = 0; v < n; ++v) {
                if (g[u][v]) {
                    if (d[u] != inf && d[v] > d[u] + g[u][v]) {
                        d[v] = -inf;
                        pre[v] = u;
                    }
                }
            }
        }
    }

    for (int i: d) {
        if (i == -inf)
            cout << "-Infinity";
        else if (i == inf)
            cout << "Impossible";
        else
            cout << i;
        cout << '\n';
    }

	return 0;
}