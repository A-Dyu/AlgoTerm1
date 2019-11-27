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
int dp[(1 << 16)][16], a[20], n, k;
vector<int> g[20];
int gcd(int a, int b) {
    if (!b)
        return a;
    return gcd(b, a % b);
}
void mem() {
    for (int mask = 0; mask < (1 << n); mask++)
        for (int i = 0; i < n; i++)
            dp[mask][i] = 0;
    for (int i = 0; i < n; i++)
        dp[(1 << i)][i] = 1;
    for (int i = 0; i < n; i++)
        g[i].clear();
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (i != j && gcd(a[i], a[j]) >= k)
                g[i].pb(j);
    for (int mask = 1; mask < (1 << n); mask++)
        for (int v = 0; v < n; v++)
            for (int i = 0; i < sz(g[v]); i++) {
                int to = g[v][i];
                if (mask & (1 << to))
                    continue;
                dp[mask ^ (1 << to)][to] =
                min(int(1e9 + 3), dp[mask ^ (1 << to)][to] + dp[mask][v]);
            }
}

void pop(int v) {
    for (int i = v; i < n - 1; i++)
        swap(a[i], a[i + 1]);
    n--;
    mem();
}

int get(int v) {
    return dp[(1 << n) - 1][v];
}
int main() {
    ifstream cin("perm.in");
    ofstream cout("perm.out");
    int m;
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n);
    mem();
    vector<int> ans;
    int last = 0;
    while (n) {
        bool f = false;
        for (int i = 0; i < n; i++)
            if (!last || gcd(a[i], last) >= k) {
                if (get(i) < m) {
                    m -= get(i);
                } else {
                    f = true;
                    ans.pb(a[i]);
                    last = a[i];
                    pop(i);
                    break;
                }
            }
        if (!f)
            break;
    }
    if (n) {
        cout << -1;
    } else {
        for (int i = 0; i < sz(ans); i++)
            cout << ans[i] << ' ';
    }
    return 0;
}
