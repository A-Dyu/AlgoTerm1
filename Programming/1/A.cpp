#include<iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio();
    cin.tie(0);
    cout.tie(0);
    int sz = 1, k = 0, n;
    int* a = (int*)malloc(sizeof(int));
    cin >> n;
    for (int i = 0; i < n; i++) {
        char c;
        cin >> c;
        if (c == '+') {
            cin >> a[k];
            k++;
            if (k == sz) {
                sz *= 2;
                a = (int*)realloc(a, sz * sizeof(int));
            }
        } else {
            k--;
            cout << a[k] << "\n";
        }
    }
    return 0;
}
