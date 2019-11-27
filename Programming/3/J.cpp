#include<iostream>
#include<vector>
#include<iomanip>
#include<unordered_map>
#include<algorithm>
#include<map>
#include<unordered_set>
#define sz(a) int(a.size())
#define ll long long
#define pb push_back
#define x first
#define y second
#define all(a) a.begin(), a.end()
#define uint unsigned long long
using namespace std;
const int N = 1e5;
const int p = int(1e6) + 3;
int dsu[N], setk[N], perk[N], setperk[N], zerg;
vector<int> g[N];
void recalc(int x) {
    perk[x] += setk[dsu[x]] - setperk[x];
    setperk[x] = setk[dsu[x]];
}
void relax(int x) {
    recalc(x);
    for (int i = 0; i < sz(g[x]); i++) {
        recalc(g[x][i]);
    }
}
void unite(int x, int y) {
    if (sz(g[x]) < sz(g[y]))
        swap(x, y);
    relax(y);
    for (int i = 0; i < sz(g[y]); i++) {
        int to = g[y][i];
        dsu[to] = x;
        setperk[to] = setk[x];
        g[x].pb(to);
    }
    g[y].clear();
    dsu[y] = x;
    setperk[y] = setk[x];
    g[x].pb(y);
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        dsu[i] = i;
    for (int i = 0; i < m; i++) {
        int t;
        cin >> t;
        if (t == 1) {
            int x;
            cin >> x;
            x = dsu[(x + zerg) % n];
            setk[x]++;
            zerg = (30 * zerg + 239) % p;
        }
        if (t == 2) {
            int x, y;
            cin >> x >> y;
            x = dsu[(x + zerg) % n];
            y = dsu[(y + zerg) % n];
            if (x == y)
                continue;
            unite(x, y);
            zerg = (13 * zerg + 11) % p;
        }
        if (t == 3) {
            int x;
            cin >> x;
            x = (x + zerg) % n;
            recalc(x);
            int q = perk[x];
            perk[x] = 0;
            cout << q << endl;
            zerg = int((1ll * 100500 * zerg + q) % p);
        }
    }
    return 0;
}

