//
// Created by Nguyen Quang Phu on 8/9/2022.
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

    int f, s, g, u, d; cin >> f >> s >> g >> u >> d;
    vector<int> vis(f + 1, 0), a(f + 1);
    vis[s] = 1, a[s] = 0;
    queue<int> qu;
    qu.push(s);
    while (!qu.empty()) {
        int x = qu.front();
        qu.pop();
        if (x == g) {
            cout << a[x] << ' ';
            return 0;
        }
        for (int y: {x + u, x - d}) {
            if (y < 1 || y > f) continue;
            if (vis[y]) continue;
            vis[y] = 1;
            a[y] = a[x] + 1;
            qu.push(y);
        }
    }
    cout << "use the stairs";

	return 0;
}