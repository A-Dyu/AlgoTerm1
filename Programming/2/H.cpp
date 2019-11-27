#include<iostream>
#include<vector>
#define sz(a) a.size()
using namespace std;
int a[1000010];
long long ans;
unsigned int cur, x1, y1, m;
int rnd() {
    cur = cur * x1 + y1;
    return (cur >> 8) % m;
}
int bin_count(int l, int r, int x) {
    int r1 = r;
    while (r - l > 1) {
        int m = (l + r) >> 1;
        if (a[m] > x)
            r = m;
        else
            l = m;
    }
    return r1 - r;
}
void add(int &i, vector<int> &v) {
    v.push_back(a[i]);
    i++;
}
void merge(int l1, int r1, int l2, int r2) {
    vector<int> v;
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
    if (l == r)
        return;
    int m = (l + r) >> 1;
    sort(l, m);
    sort(m + 1, r);
    for (int i = m + 1; i <= r; i++)
        ans += bin_count(l - 1, m + 1, a[i]);
    merge(l, m, m + 1, r);
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n >> m >> x1 >> y1;
    for (int i = 0; i < n; i++)
        a[i] = rnd();
    sort(0, n - 1);
    cout << ans;
    return 0;
}
