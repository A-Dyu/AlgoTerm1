#include<iostream>
#include<vector>
#include<iomanip>
#include<unordered_map>
#include<algorithm>
#include<map>
#include<set>
#include<fstream>
#define sz(a) int(a.size())
#define ll unsigned long long
#define pb push_back
#define x first
#define y second
#define all(a) a.begin(), a.end()
#define uint unsigned long long
using namespace std;
int dp[2][2][10010];
string s1, s2, ans;
void LCS(int g, string &x, string &y) {
    for (int i = 1; i <= sz(y); i++)
        dp[g][0][i] = dp[g][1][i] = 0;
    for (int i = 1; i <= sz(x); i++) {
        for (int j = 1; j <= sz(y); j++) {
            if (x[i - 1] == y[j - 1]) {
                dp[g][1][j] = dp[g][0][j - 1] + 1;
            } else {
                dp[g][1][j] = max(dp[g][0][j], dp[g][1][j - 1]);
            }
        }
        swap(dp[g][0], dp[g][1]);
    }
}
void getLCS(int lx, int rx, int ly, int ry) {
    if (lx == rx) {
        for (int i = ly; i <= ry; i++) {
            if (s2[i] == s1[lx]) {
                ans.pb(s2[i]);
                break;
            }
        }
        return;
    }
    string x1 = s1.substr(lx, (rx - lx + 1) / 2);
    string x2 = s1.substr(lx + (rx - lx + 1) / 2, (rx - lx + 1) / 2 + (rx - lx + 1) % 2);
    string y1 = s2.substr(ly, (ry - ly + 1)), y2 = y1;
    reverse(all(x2));
    reverse(all(y2));
    LCS(0, x1, y1);
    LCS(1, x2, y2);
    x1.clear();
    x2.clear();
    y1.clear();
    y2.clear();
    int mx = -1, j = -1, n = ry - ly + 1;
    for (int i = 1; i < n; i++)
        if (dp[0][0][i] + dp[1][0][n - i] > mx) {
            mx = dp[0][0][i] + dp[1][0][n - i];
            j = i;
        }
    if (dp[0][0][n] > mx || dp[1][0][n] > mx) {
        if (dp[0][0][n] > dp[1][0][n]) {
            getLCS(lx, lx + (rx - lx + 1) / 2 - 1, ly, ry);
        } else {
            getLCS(lx + (rx - lx + 1) / 2, rx, ly, ry);
        }
    } else {
        getLCS(lx, lx + (rx - lx + 1) / 2 - 1, ly, ly + j - 1);
        getLCS(lx + (rx - lx + 1) / 2, rx, ly + j, ry);
    }
}
int main() {
    // ifstream cin("num2choose.in");
    // ofstream cout("num2choose.out");
    cin >> s1 >> s2;
    getLCS(0, sz(s1) - 1, 0, sz(s2) - 1);
    cout << ans;
    return 0;
}
