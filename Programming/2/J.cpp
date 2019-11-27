#include<iostream>
#include<vector>
#define sz(a) int(a.size())
#define ll long long
using namespace std;
ll a[3000010], ans, k;
void add(int &i, vector<ll> &v) {
    v.push_back(a[i]);
    i++;
}
void merge(int l1, int r1, int l2, int r2) {
    vector<ll> v;
    int i = l1, j = l2;
    while (i <= r1 && j <= r2)
        if (a[i] < a[j])
            add(i, v);
        else
            add(j, v);
    while (i <= r1)
        add(i, v);
    while (j <= r2)
        add(j, v);
    for (int i = l1; i <= r2; i++)
        a[i] = v[i - l1];
    v.clear();
}
void sort(int l, int r) {
    if (l == r) {
        ans += a[l] >= k;
        return;
    }
    int m = (l + r) >> 1;
    sort(l, m);
    sort(m + 1, r);
    for (int i = m + 1; i <= r; i++) {
        ll x = a[i] - k;
        int l1 = l - 1, r1 = m + 1;
        while (r1 - l1 > 1) {
            int m1 = (l1 + r1) >> 1;
            if (a[m1] <= x)
                l1 = m1;
            else
                r1 = m1;
        }
        ans += r1 - l;
    }
    merge(l, m, m + 1, r);
}
unsigned int cur = 0, a1, b1;
unsigned int rnd24() {
    cur = cur * a1 + b1;
    return (cur >> 8);
}
int rnd() {
    unsigned int a2 = rnd24(), b2 = rnd24();
    return int((a2 << 8) ^ b2);
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n >> k >> a1 >> b1;
    for (int i = 0; i < n; i++) {
        a[i] = rnd();
        if (i)
            a[i] += a[i - 1];
    }
    sort(0, n - 1);
    cout << ans;
    return 0;
}
