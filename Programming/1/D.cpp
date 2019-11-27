#include<iostream>
using namespace std;
struct node {
    int x;
    node* nxt;
    node(int _x): x(_x), nxt() {}
};
void tie(node* old, node* tail) {
    if (old == nullptr)
        return;
    old->nxt = tail;
}
int main() {
    ios_base::sync_with_stdio();
    cin.tie(0);
    cout.tie(0);
    node* head = nullptr;
    node* tail = nullptr;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        char c;
        cin >> c;
        if (c == '+') {
            int x;
            cin >> x;
            node* d = new node(x);
            if (head == nullptr)
                head = d;
            tie(tail, d);
            tail = d;
        } else {
            cout << head->x << "\n";
            head = head->nxt;
        }
    }
    return 0;
}
