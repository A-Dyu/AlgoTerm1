#include<iostream>
#include<vector>
#define sz(a) int(a.size())
#define ll long long
#define pb push_back
#define x first
#define y second
using namespace std;
vector<pair<int, int>> ans[20];
vector<pair<int, int>> nans;
bool a[20];
int p[20];
int n, t;
void sort_net(int k) {
    if (!k)
        return;
    for (int j = 1; j < n; j += (1 << k)) {
        int l = j, r = j + (1 << k) - 1;
        while (l < r) {
            if (r <= n)
                ans[t].pb({l, r});
            l++;
            r--;
        }
    }
    if (sz(ans[t]))
        t++;
    for (int i = k - 2; i >= 0; i--) {
        for (int j = 1; j <= n; j++)
            if (((j - 1) / (1 << i)) % 2 == 0) {
                int l = j, r = j + (1 << i);
                if (r <= n)
                    ans[t].pb({l, r});
            }
        if (sz(ans[t]))
            t++;
    }
}
void sort_n() {
    t = 0;
    for (int i = 0; i < 15; i++)
        ans[i].clear();
    int ct = 0;
    while ((1 << ct) < n)
        ct++;
    for (int i = 1; i <= ct; i++)
        sort_net(i);
}
void solve(int m) {
    int k = 0, k1;
    for (int i = 0; i < m; i++)
        cin >> a[i];
    bool fl = false;
    for (int i = 0; i < m - 1; i++)
        if (a[i] > a[i + 1])
            fl = true;
    if (!fl) {
        cout << -1 << endl;
        return;
    }
    int l = m + 1, r = -1;
    for (int i = 0; i < m; i++)
        if (a[i])
            l = min(l, i);
        else
            r = max(r, i);
    for (int i = 0; i < m; i++)
        if (a[i]) {
            p[k] = i;
            k++;
        }
    n = k;
    sort_n();
    for (int i = 0; i < t; i++)
        for (int j = 0; j < sz(ans[i]); j++)
            nans.pb({p[ans[i][j].x - 1] + 1, p[ans[i][j].y - 1] + 1});
    k = 0;
    for (int i = 0; i < m; i++)
        if (!a[i]) {
            p[k] = i;
            k++;
        }
    n = k;
    k1 = k;
    sort_n();
    for (int i = 0; i < t; i++)
        for (int j = 0; j < sz(ans[i]); j++)
            nans.pb({p[ans[i][j].x - 1] + 1, p[ans[i][j].y - 1] + 1});
    k = 0;
    for (int i = 0; i < m; i++)
        if (i != l && i != r) {
            p[k] = i;
            k++;
        }
    n = k;
    sort_n();
    for (int i = 0; i < t; i++)
        for (int j = 0; j < sz(ans[i]); j++)
            nans.pb({p[ans[i][j].x - 1] + 1, p[ans[i][j].y - 1] + 1});
    n = k1;
    sort_n();
    for (int i = 0; i < t; i++)
        for (int j = 0; j < sz(ans[i]); j++)
            nans.pb({ans[i][j].x, ans[i][j].y});
    n = m - n;
    sort_n();
    for (int i = 0; i < t; i++)
        for (int j = 0; j < sz(ans[i]); j++)
            nans.pb({ans[i][j].x + k1, ans[i][j].y + k1});
    cout << sz(nans) << endl;
    for (int i = 0; i < sz(nans); i++)
        cout << nans[i].x << ' ' << nans[i].y << endl;
    nans.clear();
}
int main() {
    int m;
    cin >> m;
    while (m) {
        solve(m);
        cin >> m;
    }
    return 0;
}
