#include<iostream>
#include<vector>
#include<algorithm>
#define sz(a) a.size()
using namespace std;
int a[70010], b[70010];
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    int l = 0, r = n - 1;
    for (int i = 0; i < n; i++)
        a[i] = i;
    while (l < n) {
        int m = (l + r) >> 1;
        b[l] = a[m];
        swap(a[l], a[m]);
        l++;
    }
    for (int i = 0; i < n; i++)
        a[b[i]] = i;
    for (int i = 0; i < n; i++)
        cout << a[i] + 1 << ' ';
    return 0;
}
