#include<iostream>
#include<vector>
#define sz(a) a.size()
using namespace std;
int a[100010];
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, q;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cin >> q;
    for (int i = 0; i < q; i++) {
        int l = -1, r = n - 1, x;
        cin >> x;
        while (r - l > 1) {
            int m = (l + r) >> 1;
            if (a[m] < x)
                l = m;
            else
                r = m;
        }
        if (a[r] == x) {
            cout << r + 1 << ' ';
        } else {
            cout << "-1 -1" << endl;
            continue;
        }
        l = 0;
        r = n;
        while (r - l > 1) {
            int m = (l + r) >> 1;
            if (a[m] > x)
                r = m;
            else
                l = m;
        }
        cout << l + 1 << endl;
    }
    return 0;
}
