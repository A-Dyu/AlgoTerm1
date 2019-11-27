#include<iostream>
#include<vector>
#include<iomanip>
#include<unordered_map>
#include<algorithm>
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
int m;
void check() {
    m--;
    if (!m)
        exit(0);
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            cout << "1 " << j + 1 << ' ' << i + 1 << endl;
            check();
        }
        cout << "0 " << i + 2 << ' ' << i + 1 << endl;
        check();
    }
    return 0;
}

