#include<iostream>
#include<vector>
#define sz(a) a.size()
using namespace std;
int a[300010];
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
    merge(l, m, m + 1, r);
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(0, n - 1);
    for (int i = 0; i < n; i++)
        cout << a[i] << ' ';
    return 0;
}
