//
// Created by Nguyen Quang Phu on 8/8/2022.
//
#include <bits/stdc++.h>
#define infi 1e9 + 7
#define infll 1e18 + 7
#define all(a) (a).begin(), (a).end()
#define pb push_back
#define fi first
#define se second
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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

    int P, C, N; cin >> P >> C >> N;
    vector<vector<int>> g(P);
    for (int i = 0; i < C; ++i) {
        int u, v; cin >> u >> v;
        g[--u].pb(--v);
        g[v].pb(u);
    }
    vector<bool> vis(P, false);
    for (int i = 0; i < N; ++i) {
        int x; cin >> x;
        vis[--x] = true;
        for (int v: g[x])
            vis[v] = true;
    }

    vis[0] = true;
    int ans = 0;
    queue<int> q;
    q.push(0);
    while (!q.empty()) {
        ans++;
        int u = q.front();
        q.pop();
        for (int v: g[u]) {
            if (!vis[v]) {
                vis[v] = true;
                q.push(v);
            }
        }
    }

    cout << P - ans << "\n";

	return 0;
}