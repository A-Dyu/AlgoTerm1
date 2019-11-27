#include<iostream>
#include<vector>
#define sz(a) int(a.size())
#define ll long long
#define pb push_back
#define x first
#define y second
using namespace std;
const int N = 7 * int(1e4);
pair<unsigned int, unsigned int> a[100000];
vector<pair<unsigned int, unsigned int>> v[N];
pair<unsigned int, unsigned int> dev(unsigned int x) {
    return {x / N, x % N};
}
unsigned int cur, a1, b1;
unsigned int rnd24() {
    cur = cur * a1 + b1;
    return cur >> 8;
}
unsigned int rnd() {
    unsigned int a2 = rnd24(), b2 = rnd24();
    return (a2 << 8) ^ b2;
}
int n;
void solve() {
    for (int i = 0; i < n; i++) {
        pair<unsigned int, unsigned int> x = dev(rnd());
        v[x.y].pb(x);
    }
    int k = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < sz(v[i]); j++) {
            a[k] = v[i][j];
            k++;
        }
        v[i].clear();
    }
    for (int i = 0; i < n; i++)
        v[a[i].x].pb(a[i]);
    k = 1;
    unsigned long long ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < sz(v[i]); j++) {
            ans += 1ll * k * (v[i][j].x * N + v[i][j].y);
            k++;
        }
        v[i].clear();
    }
    cout << ans << "\n";
}
int main() {
    int t;
    cin >> t >> n >> a1 >> b1;
    for (int i = 0; i < t; i++)
        solve();
    return 0;
}
