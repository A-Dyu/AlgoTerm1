#include<iostream>
#include<vector>
#include<algorithm>
#define sz(a) a.size()
using namespace std;
int a[30000000];
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k, A, B, C;
    cin >> n >> k >> A >> B >> C >> a[0] >> a[1];
    for (int i = 2; i < n; i++)
        a[i] = A * a[i - 2] + B * a[i - 1] + C;
    int l = 0, r = n - 1;
    while (r - l > 1) {
        int v = a[(l + r) >> 1], i = l, j = r;
        while (i < j) {
            while (a[i] < v)
                i++;
            while (a[j] > v)
                j--;
            if (i < j)
                swap(a[i++], a[j--]);
        }
        if (k <= j - l + 1) {
            r = j;
        } else {
            k -= (j - l);
            l = j;
        }
    }
    if (k == 1)
        cout << min(a[l], a[r]);
    else
        cout << max(a[l], a[r]);
    return 0;
}
