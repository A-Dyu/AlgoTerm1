#include<iostream>
#include<vector>
#define sz(a) int(a.size())
#define ll long long
#define pb push_back
#define x first
#define y second
using namespace std;
vector<pair<int, int>> nt;
int n, m, k;
void check(int x) {
    vector<int> v;
    for (int i = 0; i < n; i++)
        v.pb(min(1, x & (1 << i)));
    for (int i = 0; i < m; i++)
        if (v[nt[i].x] > v[nt[i].y])
            swap(v[nt[i].x], v[nt[i].y]);
    for (int i = 0; i < n - 1; i++)
        if (v[i] > v[i + 1]) {
            cout << "No";
            exit(0);
        }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> k;
    for (int i = 0; i < k; i++) {
        int r;
        cin >> r;
        for (int j = 0; j < r; j++) {
            int x, y;
            cin >> x >> y;
            nt.pb({min(x, y) - 1, max(x, y) - 1});
        }
    }
    for (int x = 0; x < (1 << n); x++)
        check(x);
    cout << "Yes";
    return 0;
}
