#include<iostream>
#include<vector>
#include<iomanip>
#include<unordered_map>
#include<algorithm>
#include<map>
#include<unordered_set>
#include<fstream>
#define sz(a) int(a.size())
#define ll long long
#define pb push_back
#define x first
#define y second
#define all(a) a.begin(), a.end()
#define uint unsigned long long
using namespace std;
const int INF = 2e9;
int dp[300010], a[300010], pos[300010], p[300010];
vector<int> vans;
int main() {
    ifstream cin("lis.in");
    ofstream cout("lis.out");
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        dp[i] = INF;
    dp[0] = -INF;
    pos[0] = -1;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        int l = 0, r = n;
        while (r - l > 1) {
            int m = (l + r) >> 1;
            if (dp[m] > a[i])
                r = m;
            else
                l = m;
        }
        if (dp[l] < a[i]) {
            dp[r] = a[i];
            pos[r] = i;
            p[i] = pos[l];
        }
    }
    int ans = -1;
    for (int i = n; i >= 0; i--)
        if (dp[i] != INF) {
            ans = i;
            break;
        }
    cout << ans << endl;
    for (int i = pos[ans]; i != -1; i = p[i]) {
        vans.pb(a[i]);
    }
    reverse(all(vans));
    for (int i = 0; i < ans; i++)
        cout << vans[i] << ' ';
    return 0;
}

