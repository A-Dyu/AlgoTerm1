#include<iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio();
    cin.tie(0);
    cout.tie(0);
    int sz = 1, k = 0;
    int* a = (int*)malloc(sizeof(int));
    char c;
    while (cin >> c) {
        if (c >= '0' && c <= '9') {
            a[k] = c - '0';
            k++;
            if (k == sz) {
                sz *= 2;
                a = (int*)realloc(a, sz * sizeof(int));
            }
        } else {
            int x = a[k - 2], y = a[k - 1];
            if (c == '+')
                a[k - 2] = x + y;
            if (c == '-')
                a[k - 2] = x - y;
            if (c == '*')
                a[k - 2] = x * y;
            k--;
        }
    }
    cout << a[0];
    return 0;
}
