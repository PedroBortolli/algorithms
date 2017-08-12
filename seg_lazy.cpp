#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 5;
int n;
int seg[4*N];
int lazy[4*N];

void do_lazy(int root, int l, int r) {
    seg[root] += lazy[root];
    if (l != r) {
        lazy[2*root+1] += lazy[root];
        lazy[2*root+2] += lazy[root];
    }
    lazy[root] = 0;
}

int update(int l, int r, int val, int root = 0, int l2 = 0, int r2 = n-1) { //update values in range (l, r)
    do_lazy(root, l2, r2);
    if (r < l2 || l > r2) return seg[root];
    if (l2 >= l && r2 <= r) {
        lazy[root] += val;
        do_lazy(root, l2, r2);
        return seg[root];
    }
    return seg[root] = max(update(l, r, val, 2*root+1, l2, (l2+r2)/2), update(l, r, val, 2*root+2, (l2+r2)/2+1, r2));
}

int query(int l, int r, int root = 0, int l2 = 0, int r2 = n-1) { //find minimum in range (l, r)
    do_lazy(root, l2, r2);
    if (r < l2 || l > r2) return -1;
    if (l2 >= l && r2 <= r) return seg[root];
    return max(query(l, r, 2*root+1, l2, (l2+r2)/2), query(l, r, 2*root+2, (l2+r2)/2+1, r2));
}

int main() {
    int x, y;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        update(i, i, x);
    }
    for (int i = 0; i < 10000; i++) {
        scanf("%d %d", &x, &y);
        printf("%d\n", query(x-1, y-1));
    }
    return 0;
}