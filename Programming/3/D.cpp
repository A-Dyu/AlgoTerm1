#include<iostream>
#include<vector>
#include<iomanip>
#include<unordered_map>
#include<map>
#include<unordered_set>
#define sz(a) int(a.size())
#define ll long long
#define pb push_back
#define x first
#define y second
#define all(a) a.begin(), a.end()
#define uint unsigned long long
using namespace std;
int dsu[300000], n;
int get_leader(int x) {
    if (x == dsu[x])
        return x;
    return dsu[x] = get_leader(dsu[x]);
}
void unite(int x) {
    x = get_leader(x);
    int y = get_leader((x + 1) % n);
    dsu[x] = y;
}
int main() {
    cin >> n;
    for (int i = 0; i < n; i++)
        dsu[i] = i;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        x = get_leader(x - 1);
        cout << x + 1 << ' ';
        unite(x);
    }
    return 0;
}

