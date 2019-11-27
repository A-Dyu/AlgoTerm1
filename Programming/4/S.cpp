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
const ll mod = 999999937;
vector<vector<ll>> mat =
{{1, 1, 1, 1, 1},
{1, 1, 1, 1, 1},
{1, 1, 1, 1, 1},
{1, 1, 0, 1, 0},
{1, 1, 0, 1, 0}};
vector<vector<ll>> ansmat = {{1}, {1}, {1}, {1}, {1}};
vector<vector<ll>> mul(vector<vector<ll>> a, vector<vector<ll>> b) {
    vector<vector<ll>> c;
    vector<ll> lol;
    for (int i = 0; i < sz(a); i++) {
        c.pb(lol);
        for (int j = 0; j < sz(b[0]); j++) {
            c[i].pb(0);
            for (int r = 0; r < sz(b); r++) {
                c[i][j] = (c[i][j] + a[i][r] * b[r][j]) % mod;
            }
        }
    }
    return c;
}

vector<vector<ll>> pow(ll n) {
    if (n == 1)
        return mat;
    vector<vector<ll>> a = pow(n / 2);
    a = mul(a, a);
    if (n % 2)
        a = mul(a, mat);
    return a;
}
ll solve() {
    ll n;
    cin >> n;
    if (!n)
        return 0;
    if (n == 1) {
        return 5;
    }
    vector<vector<ll>> b = pow(n - 1);
    b = mul(b, ansmat);
    ll ans = 0;
    for (int i = 0; i < sz(b); i++)
        ans = (ans + b[i][0]) % mod;
    return ans;
}
int main() {
    ifstream cin("sequences.in");
    ofstream cout("sequences.out");
    while (true) {
        ll ans = solve();
        if (!ans)
            break;
        else
            cout << ans << endl;
    }
    return 0;
}

