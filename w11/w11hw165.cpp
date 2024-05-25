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


struct Node {
    Node(int idx = 0): idx(idx), in(0) {}
    vector<Node*> children;
    int idx, in;
};

struct DisjointSet {
    const int MAXN = 1e5 + 5;
    vector<Node*> nodes;
    vector<int> path;
    priority_queue<int, vector<int>, greater<int>> pq;
    DisjointSet() {
        nodes.resize(MAXN);
        rep(i, 0, MAXN, 1) nodes[i] = new Node(i);
    }
    void reset(int n) {
        rep(i, 0, n, 1) {
            nodes[i]->children.clear(); 
            nodes[i]->in = 0;
        } 
    }
    void assign(int parent, int child) {
        nodes[parent]->children.pb(nodes[child]);
        nodes[child]->in++;
    }
    vector<int> query(int n) {
        path.clear();
        rep(i, 0, n, 1) if(nodes[i]->in == 0) pq.push(i);
        while(!pq.empty()) {
            int i = pq.top();
            path.pb(i); pq.pop();
            rep(j, 0, nodes[i]->children.size(), 1) {
                nodes[i]->children[j]->in--;
                if(nodes[i]->children[j]->in == 0) pq.push(nodes[i]->children[j]->idx);
            }
        }
        return path;
    }
};

signed main() {
    // input; // annotate before submitting
    boost;
    DisjointSet dis;

    int t, n, m, a, b;
    vector<int> ans;
    cin >> t;
    while(t--) {
        cin >> n >> m;
        dis.reset(n);
        rep(i, 0, m, 1) {
            cin >> a >> b;
            dis.assign(a, b);
        }
        ans = dis.query(n);
        if(ans.size() != n) cout << "QAQ";
        else {
            rep(i, 0, n, 1) {
                cout << ans[i] << (i != n - 1 ? " " : "");
            }
        }
        cout << endl;
    }
    
    return 0;
}