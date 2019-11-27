#include<iostream>
#include<vector>
#include<iomanip>
#define sz(a) int(a.size())
#define ll long long
#define pb push_back
#define x first
#define y second
using namespace std;
double a[1000];
int main() {
    int n;
    double ans = 1e10;
    cin >> n >> a[0];
    double l = 0, r = 1e10;
    while (r - l > 0.000000001) {
        a[1] = (l + r) / 2;
        for (int i = 2; i < n; i++) {
            a[i] = (a[i - 1] + 1) * 2 - a[i - 2];
            if (a[i] <= 0) {
                l = a[1];
                break;
            }
        }
        if (l != a[1]) {
            r = a[1];
            ans = min(ans, a[n - 1]);
        }
    }
    cout << fixed << setprecision(2) << ans;
    return 0;
}
