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

typedef long long ll;
typedef pair<int, int> II;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("E:\\cp-clion\\input.inp", "r", stdin);
#endif

    const int BASE = 4000;

    int n, m, u, v, t; cin >> n >> m >> u >> v >> t;
    if (t) u--;
    t = 0;
    if ((n + m) % 2 == 0 && (u + v) % 2 == 0
    || ((n + m) % 2 == 1 && (u + v) % 2 == 1)) {
        cout << "NO\n";
        return 0;
    }

    const int dx[] = {};
    const int dy[] = {};

	return 0;
}