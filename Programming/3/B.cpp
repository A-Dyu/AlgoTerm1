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
const int N = 3e5;
int dsu[N], r[N], ct[N], mn[N], mx[N];
int get_leader(int x) {
    if (dsu[x] == x)
        return x;
    else
        return dsu[x] = get_leader(dsu[x]);
}
void merge(int x, int y) {
    x = get_leader(x);
    y = get_leader(y);
    if (x == y)
        return;
    if (r[x] < r[y])
        swap(x, y);
    mn[x] = min(mn[x], mn[y]);
    mx[x] = max(mx[x], mx[y]);
    ct[x] += ct[y];
    dsu[y] = x;
    if (r[x] == r[y])
        r[x]++;
}
int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        dsu[i] = mn[i] = mx[i] = i;
        ct[i] = 1;
    }
    string s;
    while (cin >> s)
        if (s == "get") {
            int x;
            cin >> x;
            x = get_leader(x - 1);
            cout << mn[x] + 1 << ' ' << mx[x] + 1 << ' ' << ct[x] << endl;
        } else {
            int x, y;
            cin >> x >> y;
            merge(x - 1, y - 1);
        }
    return 0;
}
