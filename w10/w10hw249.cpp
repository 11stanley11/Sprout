#pragma GCC optimize ("O2")
#pragma GCC optimize ("O3")
#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define rep(v, i, n, s) for(int v = i; s > 0 ? v < n : v > n; v += s)
#define pb push_back
#define int long long
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

const int MAXN = 1e5 + 5;

struct Node {
    int sum, max_prefix, max_suffix, max_sum;
    Node(int sum = 0, int max_prefix = 0, int max_suffix = 0, int max_sum = 0)
        : sum(sum), max_prefix(max_prefix), max_suffix(max_suffix), max_sum(max_sum) {}
};

Node merge(Node left, Node right) {
    Node result;
    result.sum = left.sum + right.sum;
    result.max_prefix = max(left.max_prefix, left.sum + right.max_prefix);
    result.max_suffix = max(right.max_suffix, right.sum + left.max_suffix);
    result.max_sum = max({left.max_sum, right.max_sum, left.max_suffix + right.max_prefix});
    return result;
}

struct SegTree {
    Node seg[4 * MAXN];
    int arr[MAXN];

    void build(int cur, int l, int r) {
        if (r - l == 1) {
            int val = arr[l];
            seg[cur] = Node(val, val, val, val);
            return;
        }
        int mid = (l + r) / 2;
        build(cur * 2 + 1, l, mid);
        build(cur * 2 + 2, mid, r);
        seg[cur] = merge(seg[cur * 2 + 1], seg[cur * 2 + 2]);
    }

    Node query(int cur, int l, int r, int ql, int qr) {
        if (ql >= r || qr <= l) return Node(0, INT_MIN, INT_MIN, INT_MIN); // Return an invalid node
        if (ql <= l && qr >= r) return seg[cur];
        int mid = (l + r) / 2;
        Node left = query(cur * 2 + 1, l, mid, ql, qr);
        Node right = query(cur * 2 + 2, mid, r, ql, qr);
        if (ql >= mid) return right; // Completely in the right segment
        if (qr <= mid) return left; // Completely in the left segment
        return merge(left, right);
    }
} st;

signed main() {
    // input; // annotate before submitting
    boost;
    
    int n, q, l, r, ans;
    cin >> n >> q;
    rep(i, 0, n, 1) cin >> st.arr[i];
    st.build(0, 0, n);
    while(q--) {
        cin >> l >> r;
        ans = st.query(0, 0, n, l-1, r).max_sum;
        cout << (ans > 0 ? ans : 0) << endl;
    }
    return 0;
}