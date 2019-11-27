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
int dsu[50010], r[50010];
int get_leader(int x) {
    if (x == dsu[x])
        return x;
    return dsu[x] = get_leader(dsu[x]);
}
void unite(int x, int y) {
    x = get_leader(x);
    y = get_leader(y);
    if (r[x] < r[y])
        swap(x, y);
    if (r[x] == r[y])
        r[x]++;
    dsu[y] = x;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++)
        dsu[i] = i;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
    }
    vector<int> t, ans;
    vector<pair<int, int>> b;
    for (int i = 0; i < k; i++) {
        string s;
        int x, y;
        cin >> s >> x >> y;
        b.pb({x - 1, y - 1});
        if (s == "ask")
            t.pb(0);
        else
            t.pb(1);
    }
    reverse(all(t));
    reverse(all(b));
    for (int i = 0; i < k; i++) {
        if (t[i]) {
            unite(b[i].x, b[i].y);
        } else {
            ans.pb(get_leader(b[i].x) == get_leader(b[i].y));
        }
    }
    reverse(all(ans));
    for (int i = 0; i < sz(ans); i++)
        if (ans[i])
            cout << "YES\n";
        else
            cout << "NO\n";
    return 0;
}

