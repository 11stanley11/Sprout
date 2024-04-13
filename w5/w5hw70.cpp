// https://neoj.sprout.tw/problem/70/
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

priority_queue<ll, vector<ll>, greater<ll>> pq;

int main() {
    // input; // annotate before submitting
    boost;
    
    ll t, n, a, b, z, sum;
    cin >> t;
    while(t--) {
        cin >> n;
        rep(i, 0, n, 1) {
            cin >> z;
            pq.push(z);
        }
        n--;
        sum = 0;
        while(n--) {
            a = pq.top(); pq.pop();
            b = pq.top(); pq.pop();
            pq.push(a + b);
            sum += a + b;
        }
        pq.pop();
        cout << sum << endl;
    }
    
    return 0;
}