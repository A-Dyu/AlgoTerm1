#include<iostream>
#include<vector>
#include<iomanip>
#include<unordered_map>
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
int dsu[2][200010];
int get_leader(int x, int d) {
    if (x == dsu[d][x])
        return x;
    return dsu[d][x] = get_leader(dsu[d][x], d);
}
void unite(int x, int y, int d) {
    x = get_leader(x, d);
    y = get_leader(y, d);
    dsu[d][x] = y;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, q;
    cin >> n >> q;
    for (int i = 0; i <= n; i++)
        dsu[0][i] = dsu[1][i] = i;
    for (int i = 0; i < q; i++) {
        int t, x, y;
        cin >> t >> x >> y;
        if (x > y)
            swap(x, y);
        if (t == 1) {
            unite(x - 1, y - 1, 0);
        }
        if (t == 2) {
            for (int i = x - 1; i < y - 1; i++) {
                i = get_leader(i, 1);
                if (i >= y - 1)
                    break;
                unite(i, i + 1, 0);
                unite(i, i + 1, 1);
            }
        }
        if (t == 3) {
            if (get_leader(x - 1, 0) == get_leader(y - 1, 0))
                cout << "YES" << "\n";
            else
                cout << "NO" << "\n";
        }
    }
    return 0;
}

