// https://neoj.sprout.tw/problem/89/
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

pii ppl[10000]; //eat make
int main() {
    // input; // annotate before submitting
    boost;
    
    int t, n, sum, flag, ans;
    cin >> t;
    while(t--) {
        cin >> n;
        if(n==0) break;
        sum=0; ans=0;
        rep(i, 0, n, 1) {
            cin >> ppl[i].ss >> ppl[i].ff;
        }
        sort(ppl, ppl+n, greater<pii>());
        rep(i, 0, n, 1) {
            sum += ppl[i].ss;
            ans = max(ans, sum+ppl[i].ff);
        }
        cout << ans << endl;
    }
    return 0;
}