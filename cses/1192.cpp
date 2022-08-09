//
// Created by Nguyen Quang Phu on 8/8/2022.
// Problem: Counting Rooms
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

    int n, m; cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m)), vis(n, vector<int>(m, 0));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) {
            char ch; cin >> ch;
            if (ch == '#')
                a[i][j] = 1;
            else
                a[i][j] = 0;
        }
    const int dx[] = {-1, 0, 0, 1};
    const int dy[] = {0, -1, 1, 0};
    auto dfs = [&] (int i, int j) {
            vis[i][j] = 1;
            stack<pair<int, int>> st;
            st.push(make_pair(i, j));
            while (!st.empty()) {
                int u = st.top().fi;
                int v = st.top().se;
                st.pop();
                for (int ii = 0; ii < 4; ++ii) {
                    int x = u + dx[ii];
                    int y = v + dy[ii];
                    if (x < 0 || x >= n || y < 0 || y >= m || vis[x][y] || a[x][y])
                        continue;
                    vis[x][y] = true;
                    st.push(make_pair(x, y));
                }
            }

        };
    int ans = 0;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            if (!vis[i][j] && !a[i][j]) {
                ans++;
                dfs(i, j);
            }
    cout << ans << '\n';

	return 0;
}
