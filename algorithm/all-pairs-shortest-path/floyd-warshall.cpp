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

    int n;
    cin >> n;
    vii g(n, vi(n));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> g[i][j];
    vii d = g;
    for (int k = 0; k < n; ++k)
        for (int u = 0; u < n; ++u)
            for (int v = 0; v < n; ++v)
                d[u][v] = min(d[u][v], d[u][k] + d[k][v]);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j)
            cout << d[i][j] << ' ';
        cout << '\n';
    }

	return 0;
}
