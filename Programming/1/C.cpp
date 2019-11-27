#include<iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio();
    cin.tie(0);
    cout.tie(0);
    int l = 0, r = 0, n, sz = 1;
    int *a = (int*)malloc(sizeof(int));
    cin >> n;
    for (int i = 0; i < n; i++) {
        char c;
        cin >> c;
        if (c == '+') {
            cin >> a[r];
            r++;
            if (r == sz) {
                sz *= 2;
                a = (int*)realloc(a, sz * sizeof(int));
            }
        } else {
            cout << a[l] << "\n";
            l++;
            if ((r - l + 1) * 4 <= sz) {
                sz /= 2;
                int* b = (int*)malloc(sz * sizeof(int));
                for (int i = 0; i < (r - l + 1); i++)
                    b[i] = a[l + i];
                free(a);
                r -= l;
                l = 0;
                a = b;
            }
        }
    }
    return 0;
}
