#include<iostream>
using namespace std;
bool solve(string s) {
    int sz = 1, k = 0;
    char* a = (char*)malloc(sizeof(char));
    for (int i = 0; i < int(s.size()); i++) {
        if (s[i] == '(' || s[i] == '[') {
            a[k] = s[i];
            k++;
            if (k == sz) {
                sz *= 2;
                a = (char*)realloc(a, sz * sizeof(char));
            }
        } else {
            if (!k || (s[i] == ')' && a[k - 1] == '[') || (s[i] == ']' && a[k - 1] == '('))
                return false;
            else
                k--;
        }
    }
    free(a);
    return !k;
}
int main() {
    ios_base::sync_with_stdio();
    cin.tie(0);
    cout.tie(0);
    string s;
    while (cin >> s)
        if (solve(s))
            cout << "YES" << "\n";
        else
            cout << "NO" << "\n";
    return 0;
}
