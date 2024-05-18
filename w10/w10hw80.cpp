#pragma GCC optimize ("O2")
#pragma GCC optimize ("O3")
#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define rep(v, i, n, s) for(int v = i; s > 0 ? v < n : v > n; v += s)
#define pb push_back
#define ll long long
#define endl '\n'
#define pii pair<int,int>
#define mpii(a, b) make_pair(a, b)
#define ff first
#define ss second
#define all(x) x.begin(),x.end()
#define boost ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define debug(x) cerr<<#x<<":"<<x<<endl;
#define debuq(x) cerr<<"debug:"<<#x<<endl;
#define input freopen("../input.in", "r", stdin)

const int MAXN = 1e6 + 6;
int arr[MAXN];

struct Node {
    Node(int l = 0, int r = 0, int v = 0) : l(l), r(r), v(v) {}
    int l, r, v;
};

struct SegTree {
    Node seg[2*MAXN];
    void build(int cur, int l, int r) {
        seg[cur] = Node(l, r);
        if(r - l == 1) {
            seg[cur].v = arr[l];
            return;
        }
        int mid = (l + r) / 2;
        build(cur*2 + 1, l, mid);
        build(cur*2 + 2, mid, r);
        seg[cur].l = l;
        seg[cur].r = r;
        seg[cur].v = min(seg[cur*2 + 1].v, seg[cur*2 + 2].v);
    }
    void update(int cur, int pos, int val) {
        if(seg[cur].r - seg[cur].l == 1) {
            seg[cur].v = val;
            return;
        }
        int mid = (seg[cur].l + seg[cur].r) / 2;
        if(pos < mid) update(cur*2 + 1, pos, val);
        else update(cur*2 + 2, pos, val);
        seg[cur].v = min(seg[cur*2 + 1].v, seg[cur*2 + 2].v);
    }
    int query(int cur, int l, int r) {
        if(seg[cur].l == l && seg[cur].r == r) return seg[cur].v;
        int mid = (seg[cur].l + seg[cur].r) / 2;
        if(r <= mid) return query(cur*2 + 1, l, r);
        else if(l >= mid) return query(cur*2 + 2, l, r);
        else return min(query(cur*2 + 1, l, mid), query(cur*2 + 2, mid, r));
    }
} st;

signed main() {
    // input; // annotate before submitting
    boost;
    
    int t, n, c, x, y;
    cin >> t >> n;
    rep(i, 0, n, 1) cin >> arr[i];
    st.build(0, 0, n);
    while(t--) {
        cin >> c >> x >> y;
        if(c == 1) cout << st.query(0, x, y+1) << endl;
        else st.update(0, x, y);
    }
    
    return 0;
}