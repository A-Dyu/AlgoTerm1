#include<iostream>
#include<vector>
#include<algorithm>
#define sz(a) int(a.size())
#define pb push_back
using namespace std;
vector<string> v, ct[30];
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        v.pb(s);
    }
    for (int t = 0; t < k; t++) {
        for (int i = 0; i < n; i++)
            ct[v[i][m - 1 - t] - 'a'].pb(v[i]);
        v.clear();
        for (int i = 0; i <= 'z' - 'a'; i++)
            for (int j = 0; j < sz(ct[i]); j++)
                v.pb(ct[i][j]);
        for (int i = 0; i <= 'z' - 'a'; i++)
            ct[i].clear();
    }
    for (int i = 0; i < n; i++)
        cout << v[i] << endl;
    return 0;
}
