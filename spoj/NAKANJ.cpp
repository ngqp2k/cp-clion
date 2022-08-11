//
// Created by Nguyen Quang Phu on 8/9/2022.
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
typedef pair<int, int> II;

const int dx[] = {-2,-1, 1, 2, 2, 1, -1, -2};
const int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};

int vis[8][8], d[8][8];

void solve() {
    string s1, s2; cin >> s1 >> s2;
    int n = s1[0] - 'a', m = s1[1] - '0' - 1, p = s2[0] - 'a', q = s2[1] - '0' - 1;
    int ans = 0;
    memset(vis, 0, sizeof vis);
    memset(d, 0, sizeof d);
    vis[n][m] = 1, d[n][m] = 0;
    queue<II> qu;
    qu.push(mp(n, m));
    while (!qu.empty()) {
        ans++;
        auto i = qu.front();
        qu.pop();
        if (i.fi == p && i.se == q) {
            cout << d[i.fi][i.se] << '\n';
            return;
        }
        for (int j = 0; j < 8; ++j) {
            int x = i.fi + dx[j];
            int y = i.se + dy[j];
            if (x < 0 || x > 7 || y < 0 || y > 7) continue;
            if (vis[x][y]) continue;
            vis[x][y] = 1, d[x][y] = d[i.fi][i.se] + 1;
            qu.push(mp(x, y));
        }
    }
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