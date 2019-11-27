#include<iostream>
#include<vector>
#define sz(a) a.size()
#define ll long long
using namespace std;
const int N = int(1e5) + 11;
ll a[N], b[N], t[N], d[N], m, n, p;
void add(int &i, vector<ll> &v) {
    v.push_back(d[i]);
    i++;
}
void merge(int l1, int r1, int l2, int r2) {
    vector<ll> v;
    int i = l1, j = l2;
    while (i <= r1 && j <= r2)
        if (d[i] > d[j])
            add(i, v);
        else
            add(j, v);
    while (i <= r1)
        add(i, v);
    while (j <= r2)
        add(j, v);
    for (int i = l1; i <= r2; i++)
        d[i] = v[i - l1];
    v.clear();
}
void sort(int l, int r) {
    if (l == r)
        return;
    int m = (l + r) >> 1;
    sort(l, m);
    sort(m + 1, r);
    merge(l, m, m + 1, r);
}
bool check(ll x) {
    for (int i = 0; i < m; i++)
        if (a[i])
            d[i] = max(0ll, (x - t[i] - b[i]) / a[i]);
        else
            d[i] = (x >= t[i] + b[i]) * p;
    sort(0, int(m - 1));
    ll ct = 0;
    for (int i = 0; i < min(n, m); i++)
        ct += d[i];
    return ct >= p;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> m;
    for (int i = 0; i < m; i++)
        cin >> a[i] >> b[i] >> t[i];
    cin >> n >> p;
    ll l = -1, r = 1e11;
    while (r - l > 1) {
        ll m = (l + r) >> 1;
        if (check(m))
            r = m;
        else
            l = m;
    }
    cout << r;
    return 0;
}
