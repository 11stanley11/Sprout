// https://neoj.sprout.tw/problem/48/
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
    Node(int data) : data(data), left(NULL), right(NULL) {}
    public:
        int data;
    Node* left;
    Node* right;
};


void AddNode(Node* n, int data) {
    while(true) {
        if(data < n -> data) {
            if(n -> left == NULL) {
                n -> left = new Node(data);
                break;
            }
            n = n -> left;
        }else{
            if(n -> right == NULL) {
                n -> right = new Node(data);
                break;
            }
            n = n -> right;
        }
    }
}

void PostorderTraversal(Node* n) {
    if(n == NULL) return;
    PostorderTraversal(n -> left);
    PostorderTraversal(n -> right);
    cout << n -> data << endl;
}

int main()
{
    // input; // annotate before submitting
    boost;

    int n, d;
    cin >> n;
    Node* root = NULL;
    while(n--) {
        cin >> d;
        if (root == NULL) {
            root = new Node(d);
        }else{
            AddNode(root, d);
        }
    }
    PostorderTraversal(root);

    return 0;
}