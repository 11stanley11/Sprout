// https://neoj.sprout.tw/problem/293/
#pragma GCC optimize ("O2")
#pragma GCC optimize ("O3")
#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define rep(v, i, n, s) for(int v = i; v < n; v += s)
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
#define input freopen("input.in", "r", stdin)

struct Node {
    vector<pair<Node*, int>> branch;
    void push(Node* n) {
        branch.push_back({n, 0});
    }
    int findNodeLength(Node* n) {
        auto idx = find_if(all(branch), [&](const pair<Node*, int>& p) {
            return p.first == n;
        });
        if(idx != branch.end()) return idx -> ss;
        return 0;
    }
    int findMaximun() {
        int maxi = 0;
        for(auto& p : branch) {
            if(maxi < p.ss) maxi = p.ss;
        }
        return maxi;
    }
};

int n;

int solveTotal(Node* to, Node* from) {
    int total = 1;
    int tmp = -1;
    rep(i, 0, to -> branch.size(), 1) {
        if(to -> branch[i].ff == from) {
            tmp = i;
            continue;
        }
        to -> branch[i].ss = solveTotal(to -> branch[i].ff, to) - to -> branch[i].ff -> findNodeLength(to);
        total += to -> branch[i].ss;
    }
    if(tmp != -1) to -> branch[tmp].ss = n - total; 
    return n;
}

void connect(Node* a, Node* b) {
    a -> push(b);
    b -> push(a);
}

vector<Node*> tree(int(1e5));

int main() {
    // input; // annotate before submitting
    boost;
    
    int t, mini, ans;
    cin >> t;
    while(t--) {
        cin >> n;
        rep(i, 0, n, 1) {
            tree[i] = new Node();
        }
        rep(i, 1, n, 1) {
            int a, b;
            cin >> a >> b;
            connect(tree[a], tree[b]);
        }
        solveTotal(tree[0], NULL);
        // rep(i, 0, n, 1) { // check
        //     cout << tree[i] -> findMaximun() << " "; // brief check
        // }
        // cout << endl;
        mini = INT_MAX;
        rep(i, 0, n, 1) { // check
            if(mini > tree[i] -> findMaximun()) {
                mini = tree[i] -> findMaximun();
                ans = i;
            }
        }
        cout << ans << endl;
        rep(i, 0, n, 1) {
            delete tree[i];
        }
    }
    
    return 0;
}