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
struct elem {
    int x;
    int p;
    elem(int _x, int _p): x(_x), p(_p) {}
};
bool operator <(elem &a, elem &b) {
    return a.x < b.x;
}
vector<elem> heap;
vector<int> pos;
void upd(int i) {
    pos[heap[i].p] = i;
}
void swp(int i, int j) {
    swap(heap[i], heap[j]);
    upd(i);
    upd(j);
}
void push_up(int i) {
    while (i && heap[i] < heap[(i - 1) / 2]) {
        swp(i, (i - 1) / 2);
        i = (i - 1) / 2;
    }
}
void push_down(int i) {
    while (i < sz(heap)) {
        int to;
        if (i * 2 + 2 < sz(heap) && heap[i * 2 + 2] < heap[i * 2 + 1])
            to = i * 2 + 2;
        else
            to = i * 2 + 1;
        if (to >= sz(heap))
            return;
        if (heap[i] < heap[to])
            return;
        swp(i, to);
        i = to;
    }
}
void add(int x) {
    heap.pb(elem(x, sz(pos)));
    pos.pb(sz(heap) - 1);
    push_up(sz(heap) - 1);
}
void del() {
    if (!sz(heap)) {
        cout << '*' << endl;
        return;
    }
    swp(0, sz(heap) - 1);
    cout << heap[sz(heap) - 1].x << ' ' << heap[sz(heap) - 1].p + 1 << endl;
    heap.pop_back();
    push_down(0);
}
void decrease(int p, int d) {
    int i = pos[p];
    if (i >= sz(heap))
        return;
    heap[i].x = d;
    push_up(i);
}
int main() {
    string s;
    while (cin >> s) {
        if (s == "push") {
            int x;
            cin >> x;
            add(x);
        }
        if (s == "extract-min") {
            del();
            pos.pb(-1);
        }
        if (s == "decrease-key") {
            int p, d;
            cin >> p >> d;
            decrease(p - 1, d);
            pos.pb(-1);
        }
    }
    return 0;
}

