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
ll dp[500][500], a[500], b[500];
int boarder[500][500];
string ans;
ll count(int l, int r) {
    if (r - l == 1)
        dp[l][r] = 0;
    if (dp[l][r] != -1)
        return dp[l][r];
    dp[l][r] = 4e18;
    for (int i = l + 1; i < r; i++) {
        if (dp[l][r] > (count(l, i) + count(i, r) + a[l] * a[i] * b[r - 1])) {
            dp[l][r] = (count(l, i) + count(i, r) + a[l] * a[i] * b[r - 1]);
            boarder[l][r] = i;
        }
    }
    return dp[l][r];
}
void get_ans(int l, int r) {
    if (r - l == 1) {
        ans += 'A';
        return;
    }
    ans += '(';
    get_ans(l, boarder[l][r]);
    get_ans(boarder[l][r], r);
    ans += ')';
}
int main() {
    ifstream cin("matrix.in");
    ofstream cout("matrix.out");
    int n;
    cin >> n;
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= n; j++)
            dp[i][j] = -1;
    for (int i = 0; i < n; i++)
        cin >> a[i] >> b[i];
    count(0, n);
    get_ans(0, n);
    cout << ans;
    return 0;
}

