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
const int INF = int(2e9) + 111;
int dp[(1 << 18)][18];
vector<pair<int, int>> g[20];
int main() {
    ifstream cin("salesman.in");
    ofstream cout("salesman.out");
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x, y, c;
        cin >> x >> y >> c;
        g[x - 1].pb({y - 1, c});
        g[y - 1].pb({x - 1, c});
    }
    for (int mask = 0; mask < (1 << n); mask++)
        for (int i = 0; i < n; i++)
            dp[mask][i] = INF;
    for (int i = 0; i < n; i++)
        dp[(1 << i)][i] = 0;
    for (int mask = 1; mask < (1 << n); mask++)
        for (int v = 0; v < n; v++)
            for (int i = 0; i < sz(g[v]); i++) {
                int to = g[v][i].x, c = g[v][i].y;
                if (!(mask & (1 << to)))
                    dp[mask ^ (1 << to)][to] = min(dp[mask ^ (1 << to)][to], dp[mask][v] + c);
            }
    int ans = INF, mask = (1 << n) - 1;
    for (int i = 0; i < n; i++)
        ans = min(ans, dp[mask][i]);
    cout << (ans == INF ? -1 : ans);
    return 0;
}

