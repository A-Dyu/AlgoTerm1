#include<iostream>
#include<vector>
#include<iomanip>
#include<unordered_map>
#include<algorithm>
#include<map>
#include<unordered_set>
#include<fstream>
#define sz(a) int(a.size())
#define ll long long
#define pb push_back
#define x first
#define y second
#define all(a) a.begin(), a.end()
#define uint unsigned long long
using namespace std;
ll dp[100000][2];
vector<pair<int, ll>> g[100000];
void dfs(int v, int p) {
    for (int i = 0; i < sz(g[v]); i++) {
        int to = g[v][i].x;
        if (to == p)
            continue;
        dfs(to, v);
    }
    if (sz(g[v]) == 1 && p != -1)
        return;
    ll mx = -int(2e18);
    for (int i = 0; i < sz(g[v]); i++) {
        int to = g[v][i].x;
        ll c = g[v][i].y;
        if (to == p)
            continue;
        dp[v][0] += max(dp[to][0], dp[to][1]);
        mx = max(mx, c - max(dp[to][0], dp[to][1]) + dp[to][0]);
    }
    dp[v][1] = dp[v][0] + mx;
}
int main() {
    ifstream cin("matching.in");
    ofstream cout("matching.out");
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int x, y;
        ll c;
        cin >> x >> y >> c;
        g[x - 1].pb({y - 1, c});
        g[y - 1].pb({x - 1, c});
    }
    dfs(0, -1);
    cout << max(dp[0][0], dp[0][1]);
    return 0;
}

