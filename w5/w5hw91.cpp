// https://neoj.sprout.tw/problem/91/
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
#define input freopen("input.in", "r", stdin)

stack<ll> q;
ll t, n;

int main() {
    // input; // annotate before submitting
    boost;
    
    cin >> t;
    while(t--) {
        cin >> n;
        rep(i, 9, 1, -1) {
            while(n%i == 0 && n!=1) {
                q.push(i);
                n = n / i;
            }
        }
        if(n==1 && !q.empty()) {
            while(!q.empty()) {
                cout << q.top();
                q.pop();
            }
        }
        else if(n==1) cout << 1;
        else {
            cout << -1;
            while(!q.empty()) {
                q.pop();
            }
        }
        cout << endl;
    }
    
    return 0;
}