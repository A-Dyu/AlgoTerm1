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
int dsu[300010], col[300010];
int get_leader(int x) {
    if (x == dsu[x])
        return x;
    return dsu[x] = get_leader(dsu[x]);
}
void unite(int x, int y) {
    x = get_leader(x);
    y = get_leader(y);
    dsu[x] = y;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i <= n; i++) {
        dsu[i] = i;
        col[i] = INT_MAX;
    }
    vector<pair<int, pair<int, int>>> v;
    for (int i = 0; i < m; i++) {
        int x, y, c;
        cin >> x >> y >> c;
        v.pb({c, {x - 1, y - 1}});
    }
    sort(all(v));
    reverse(all(v));
    for (int i = 0; i < m; i++) {
        int x = v[i].y.x, y = v[i].y.y, c = v[i].x;
        for (int j = get_leader(x); j <= y; j = get_leader(j + 1)) {
            col[j] = c;
            unite(j, j + 1);
        }
    }
    for (int i = 0; i < n; i++)
        cout << col[i] << ' ';
    return 0;
}

