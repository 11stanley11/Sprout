// https://neoj.sprout.tw/problem/138/
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

const int MAXN = 1e5 + 1;
const int mod = 1e6 + 7;
int dp[MAXN];
int pre[MAXN];

signed main() {
    // input; // annotate before submitting
    boost;
    
    //bottom up
    dp[0] = 0;
    dp[2] = 3;
    pre[0] = 1;
    rep(i, 4, MAXN, 2) {
        dp[i] = (3 * dp[i - 2] + 2 * pre[i-4]) % mod;
        pre[i-2] = (pre[i-4] + dp[i-2]) % mod;
    }
    
    int t, n;
    cin >> t;
    while(t--) {
        cin >> n;
        if(n%2==0) cout << dp[n] << endl;
        else cout << 0 << endl;
    }
    
    return 0;
}