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
int dp[1001][10001], b[1001], c[1001];
vector<int> ans;
int main() {
    ifstream cin("knapsack.in");
    ofstream cout("knapsack.out");
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> b[i];
    for (int i = 0; i < n; i++)
        cin >> c[i];
    for (int i = 0; i < n; i++)
        for (int j = 0; j <= m; j++) {
            dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
            if (j + b[i] <= m)
                dp[i + 1][j + b[i]] = max(dp[i + 1][j + b[i]], dp[i][j] + c[i]);
        }
    int mx = -1, j = -1;
    for (int i = 0; i <= m; i++)
        if (dp[n][i] > mx) {
            mx = dp[n][i];
            j = i;
        }
    for (int i = n; i > 0; i--) {
        if (dp[i - 1][j] != dp[i][j]) {
            ans.pb(i);
            j -= b[i - 1];
        }
    }
    cout << sz(ans) << endl;
    reverse(all(ans));
    for (int i = 0; i < sz(ans); i++)
        cout << ans[i] << ' ';
    return 0;
}

