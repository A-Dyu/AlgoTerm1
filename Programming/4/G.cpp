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
int dp[(1 << 20)];
int a[20], b[20], c[20], n;
int count_d(int mask) {
    int ans = 0;
    for (int i = 0; i < n; i++)
        if (mask & (1 << i))
            ans += c[i];
    return ans;
}
int count(int mask) {
    int ans = 0;
    while (mask) {
        ans += mask & 1;
        mask = mask >> 1;
    }
    return ans;
}
int get_v(int mask) {
    for (int i = 0; i < n; i++)
        if (mask & (1 << i))
            return i;
    return -1;
}
int get_p(int mask1, int mask2) {
    int mask = mask1 ^ mask2;
    return get_v(mask);
}
int main() {
    ifstream cin("meetings.in");
    ofstream cout("meetings.out");
    int k;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i] >> c[i];
        if (a[i] <= k && b[i] >= k)
            dp[(1 << i)] = -1;
    }
    int ans = 0, mans = -1;
    for (int mask = 1; mask < (1 << n); mask++)
        if (dp[mask]) {
            if (count(mask) > ans) {
                ans = count(mask);
                mans = mask;
            }
            int d = count_d(mask) + k;
            for (int i = 0; i < n; i++)
                if (a[i] <= d && b[i] >= d && !(mask & (1 << i)))
                    dp[mask ^ (1 << i)] = mask;
        }
    if (!ans) {
        cout << 0;
        return 0;
    }
    vector<int> vans;
    while (dp[mans] != -1) {
        vans.pb(get_p(dp[mans], mans));
        mans = dp[mans];
    }
    vans.pb(get_v(mans));
    cout << sz(vans) << endl;
    reverse(all(vans));
    for (int i = 0; i < sz(vans); i++)
        cout << vans[i] + 1 << ' ';
    return 0;
}
