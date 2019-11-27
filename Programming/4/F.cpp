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
bool dp[10010][10010];
int main() {
    // ifstream cin("meetings.in");
    // ofstream cout("meetings.out");
    string s1, s2;
    getline(cin, s2);
    getline(cin, s1);
    int n = sz(s1), m = sz(s2);
    if (!m && n) {
        cout << "NO";
        return 0;
    }
    if (!n) {
        for (int i = 0; i < m; i++)
            if (s2[i] != '*') {
                cout << "NO";
                return 0;
            }
        cout << "YES";
        return 0;
    }
    dp[0][0] = true;
    for (int j = 1; j <= m && s2[j - 1] == '*'; j++)
        dp[0][j] = true;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            if (s2[j - 1] == '?') {
                dp[i][j] = dp[i - 1][j - 1];
            } else if (s2[j - 1] == '*') {
                dp[i][j] = dp[i - 1][j] || dp[i][j - 1] || dp[i - 1][j - 1];
            } else if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            }
        }
    if (dp[n][m])
        cout << "YES";
    else
        cout << "NO";
    return 0;
}
