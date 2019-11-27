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
int a[100000];
int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        if ((2 * i + 1 < n && a[i] > a[2 * i + 1]) || (2 * i + 2 < n && a[i] > a[2 * i + 2])) {
            cout << "NO";
            return 0;
        }
    cout << "YES";
    return 0;
}
