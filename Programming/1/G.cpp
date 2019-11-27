#include<iostream>
#define x first
#define y second
#define ll int
using namespace std;
struct vec {
    int k;
    pair<ll, ll>* v;
    vec(): k(0), v(nullptr) {}
};
vec a, b;
ll x1, x2, x3, l1, l2, k;
void add(vec &c, ll x) {
    c.v[c.k] = {x, x};
    if (c.k)
        c.v[c.k].y = min(x, c.v[c.k - 1].y);
    c.k++;
}
void move() {
    while (b.k) {
        add(a, b.v[b.k - 1].x);
        b.k--;
    }
}
ll del() {
    if (!a.k)
        move();
    ll ans = a.v[a.k - 1].y;
    if (b.k)
        ans = min(ans, b.v[b.k - 1].y);
    a.k--;
    return ans;
}
ll get() {
    ll x;
    if (k) {
        cin >> x;
        k--;
    } else {
        x = int(x1 * l1 + x2 * l2 + x3);
    }
    l1 = l2;
    l2 = x;
    return x;
}
void print(vec a) {
    a.k--;
    while (a.k >= 0) {
        cout << a.v[a.k].x << ' ' << a.v[a.k].y << endl;
        a.k--;
    }
}
int main() {
    ios_base::sync_with_stdio();
    cin.tie(0);
    cout.tie(0);
    long long ans = 0;
    int n, m;
    cin >> n >> m >> k >> x1 >> x2 >> x3;
    a.v = (pair<ll, ll>*)malloc(m * sizeof(pair<ll, ll>));
    b.v = (pair<ll, ll>*)malloc(m * sizeof(pair<ll, ll>));
    for (int i = 0; i < m; i++)
        add(b, get());
    for (int i = m; i < n; i++) {
        ans += del();
        add(b, get());
    }
    ans += del();
    cout << ans;
    return 0;
}
