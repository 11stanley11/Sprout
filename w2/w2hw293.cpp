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
    Node(): total(1) {}
    int total;
    vector<pair<Node*, int>> branch;
    void push(Node* n, int length) {
        total += length;
        branch.push_back({n, length});
    }
    void change(Node* n ,int length) {
        auto idx = find_if(all(branch), [&](const pair<Node*, int>& p) {
            return p.first == n;
        });
        if(idx != branch.end()) {
            total = total - idx -> ss + length;
            idx -> ss = length;
        }
    }
    int findMaximun() {
        int maxi = 0;
        for(auto& p : branch) {
            if(maxi < p.ss) maxi = p.ss;
        }
        return maxi;
    }
};

void changeToAllBranches(Node* to, Node* from) {
    for(auto& p : to -> branch) {
        if(p.ff == from) continue;
        p.ff -> change(to, to -> total - p.ss);
        changeToAllBranches(p.ff, to);
    }
}

void connect(Node* a, Node* b) {
    int tmp = a -> total;
    a -> push(b, b -> total);
    changeToAllBranches(a, b);
    b -> push(a, tmp);
    changeToAllBranches(b, a);
}

vector<Node*> tree(int(1e5));

int main() {
    input; // annotate before submitting
    boost;
    
    int t, n, mini, ans;
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
            // rep(i, 0, n, 1) { // check
            //     cout << tree[i] -> findMaximun() << " "; // brief check
            // }
            // cout << endl;
        }
        mini = INT_MAX;
        rep(i, 0, n, 1) { // check
            if(mini > tree[i] -> findMaximun()) {
                mini = tree[i] -> findMaximun();
                ans = i;
            }
        }
        cout << ans << endl;
        
    }
    
    return 0;
}