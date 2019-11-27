#include<iostream>
using namespace std;
struct node {
    int x;
    node* prev;
    node(int _x, node* _prev): x(_x), prev(_prev) {}
};
int main() {
    ios_base::sync_with_stdio();
    cin.tie(0);
    cout.tie(0);
    node* t = nullptr;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        char c;
        cin >> c;
        if (c == '+') {
            int x;
            cin >> x;
            t = new node(x, t);
        } else {
            cout << t->x << "\n";
            t = t->prev;
        }
    }
    return 0;
}
