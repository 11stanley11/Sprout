// https://neoj.sprout.tw/problem/49/
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
    Node(int data, Node* ptr): data(data), root(ptr) {}
    public:
        int data;
    Node* root;
};

vector<Node*> box(int(1e6));

void moveNode(Node* from, Node* to) {
    from -> root = to;
    Node* temp = to;
    while(temp != NULL) {
        temp -> data += from -> data;   
        temp = temp -> root;
    }
}

int main() {
    // input; // annotate before submitting
    boost;
    
    int t, n, m, x, y, q;
    cin >> t;
    while(t--) {
        cin >> n >> m;
        rep(i, 0, n, 1) {
            box[i] = new Node(1, NULL);
        }
        while(m--) {
            cin >> x >> y;
            moveNode(box[y-1], box[x-1]);
        }
        cin >> q;
        while(q--) {
            cin >> x;
            cout << box[x-1] -> data << endl;
        }
    }
    
    return 0;
}