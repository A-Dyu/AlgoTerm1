#include<iostream>
#include <vector>
#include <fstream>

#define sz(a) int(a.size())
#define ll long long
#define pb push_back
#define x first
#define y second
#define all(a) a.begin(), a.end()
#define uint unsigned long long
using namespace std;
string dp[1020][1020];
bool operator <(string &a, string &b) {
    if (sz(a) != sz(b)) {
        return sz(a) < sz(b);
    }
    for (int i = 0; i < sz(a); i++)
        if (a[i] != b[i]) {
            return a[i] < b[i];
        }
    return false;
}
pair<int, int> q[1000100];
int n, head, tail;
void bfs() {
    pair<int, int> p = q[tail++];
    if (p == pair(n, 0)) {
        head = tail;
        return;
    }
    for (int k = (p == pair(0, 0) ? 1 : 0); k < 10; k++) {
        pair<int, int> to = {p.x + k, (p.y * 10 + k) % n};
        string new_string = dp[p.x][p.y] + to_string(k);
        if (to.x > n)
            break;
        if (dp[to.x][to.y] == "") {
            q[head++] = to;
            dp[to.x][to.y] = dp[p.x][p.y] + to_string(k);
        }
        if (new_string < dp[to.x][to.y])
            dp[to.x][to.y] = new_string;
    }
}
int main() {
    ifstream cin("number.in");
    ofstream cout("number.out");
    cin >> n;
    q[head++] = {0, 0};
    while (head != tail) {
        bfs();
    }
    cout << dp[n][0];
    return 0;
}


