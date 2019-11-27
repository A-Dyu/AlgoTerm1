#include<iostream>
#include<vector>
#define sz(a) int(a.size())
#define ll long long
#define pb push_back
#define x first
#define y second
using namespace std;
vector<pair<int, int>> ans[20];
int n, t = 0;
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
int main() {
    cin >> n;
    for (int i = 1; i < 5; i++)
        sort_net(i);
    int s = 0;
    for (int i = 0; i < t; i++)
        s += sz(ans[i]);
    cout << n << ' ' << s << ' ' << t << endl;
    for (int i = 0; i < t; i++) {
        cout << sz(ans[i]) << ' ';
        for (int j = 0; j < sz(ans[i]); j++)
            cout << ans[i][j].x << ' ' << ans[i][j].y << ' ';
        cout << endl;
    }
    return 0;
}
