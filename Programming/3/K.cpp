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
struct node {
    int x, rank, heap, id;
    node* p;
    node* v[20];
    node(int _x, int _id) {
        x = _x;
        id = _id;
        p = nullptr;
        rank = 0;
        heap = -1;
        for (int j = 0; j < 20; j++)
            v[j] = nullptr;
    }
};
node* heaps[1001][20];
node* nodes[1000001];
void print_node(node* t) {
    if (t == nullptr)
        return;
    cout << t->x << endl;
    for (int j = 0; j < 20; j++)
        print_node(t->v[j]);
}
void print_heap(int i) {
    for (int j = 0; j < 20; j++)
        print_node(heaps[i][j]);
}
int nodek;
void clr(int i) {
    for (int j = 0; j < 20; j++)
        heaps[i][j] = nullptr;
}
void mix(node* x, node* y) {
    x->rank++;
    x->v[y->rank] = y;
    y->p = x;
}
void merge(int x, int y) {
    vector<node*> v;
    for (int k = 0; k < 20; k++) {
        if (heaps[x][k] != nullptr)
            v.pb(heaps[x][k]);
        if (heaps[y][k] != nullptr)
            v.pb(heaps[y][k]);
    }
    clr(x);
    clr(y);
    for (int i = 1; i < sz(v); i++)
        if (v[i - 1]->rank == v[i]->rank) {
            if (v[i]->x > v[i - 1]->x)
                swap(v[i], v[i - 1]);
            mix(v[i], v[i - 1]);
            v[i - 1] = nullptr;
            if (i < sz(v) - 1 && v[i]->rank > v[i + 1]->rank)
                swap(v[i], v[i + 1]);
        }
    for (int i = 0; i < sz(v); i++)
        if (v[i] != nullptr) {
            heaps[x][v[i]->rank] = v[i];
        }
    for (int j = 0; j < 20; j++)
        if (heaps[x][j] != nullptr)
            heaps[x][j]->heap = x;
}
void add(int v, int a) {
    nodek++;
    nodes[nodek] = new node(v, nodek);
    heaps[1000][0] = nodes[nodek];
    merge(a, 1000);
}
void save_children(node* t) {
    for (int j = 0; j < 20; j++)
        if (t->v[j] != nullptr) {
            t->v[j]->p = nullptr;
            heaps[1000][j] = t->v[j];
        }
}
void extract_min(int i) {
    int mn = INT_MAX, pos = 1000;
    for (int j = 0; j < 20; j++)
        if (heaps[i][j] != nullptr && mn > heaps[i][j]->x) {
            pos = j;
            mn = heaps[i][j]->x;
        }
    save_children(heaps[i][pos]);
    heaps[i][pos] = nullptr;
    merge(i, 1000);
}
int get_heap(node* t) {
    while (t->p != nullptr)
        t = t->p;
    return t->heap;
}
void swap_nodes(node* x, node* y) {
    swap(x->x, y->x);
    swap(x->id, y->id);
    swap(nodes[x->id], nodes[y->id]);
}
void push_up(node* t) {
    while (t->p != nullptr && t->x < t->p->x) {
        swap_nodes(t, t->p);
        t = t->p;
    }
}
void push_down(node* t) {
    while (true) {
        int mn = INT_MAX, pos = -1;
        for (int j = 0; j < 20; j++)
            if (t->v[j] != nullptr) {
                if (mn > t->v[j]->x) {
                    mn = t->v[j]->x;
                    pos = j;
                }
            }
        if (mn < t->x) {
            swap_nodes(t, t->v[pos]);
            t = t->v[pos];
        } else {
            break;
        }
    }
}
void set_key(int p, int x) {
    node* t = nodes[p];
    if (t == nullptr)
        cout << '+';
    t->heap = get_heap(t);
    t->x = x;
    push_up(t);
    push_down(nodes[p]);
}
void del(int p) {
    set_key(p, INT_MIN);
    extract_min(nodes[p]->heap);
}
int get_min(int i) {
    int ans = INT_MAX;
    for (int j = 0; j < 20; j++)
        if (heaps[i][j] != nullptr) {
            ans = min(ans, heaps[i][j]->x);
        }
    return ans;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, q;
    cin >> n >> q;
    for (int lol = 0; lol < q; lol++) {
        int t;
        cin >> t;
        if (t == 0) {
            int v, a;
            cin >> a >> v;
            add(v, a - 1);
        }
        if (t == 1) {
            int a, b;
            cin >> a >> b;
            merge(b - 1, a - 1);
        }
        if (t == 2) {
            int i;
            cin >> i;
            del(i);
        }
        if (t == 3) {
            int i, v;
            cin >> i >> v;
            set_key(i, v);
        }
        if (t == 4) {
            int a;
            cin >> a;
            cout << get_min(a - 1) << endl;
        }
        if (t == 5) {
            int a;
            cin >> a;
            extract_min(a - 1);
        }
    }
    return 0;
}

