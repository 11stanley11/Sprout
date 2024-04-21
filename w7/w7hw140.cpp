// https://neoj.sprout.tw/problem/140/
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
const int MOD = 1e6 + 7;
int dp[MAXN][3][3]; //0 1 2 R G B
int sum[MAXN];

signed main() {
    // input; // annotate before submitting
    boost;

    //bottom up
    memset(sum, 0, sizeof(0));
    rep(i, 0, 3, 1) rep(j, 0, 3 ,1) {
        if(i == j) dp[1][i][j] = 1;
        else dp[1][i][j] = 0;
        sum[1] += dp[1][i][j]; 
    }
    rep(i, 2, MAXN, 1) rep(j, 0, 3, 1) {
        dp[i][0][j] = (dp[i-1][0][j] + dp[i-1][1][j] + dp[i-1][2][j]) % MOD; // red
        dp[i][1][j] = (dp[i-1][0][j] + dp[i-1][1][j]) % MOD; // blue
        dp[i][2][j] = (dp[i-1][0][j] + dp[i-1][2][j]) % MOD; // green
        sum[i] += (dp[i][0][j] + dp[i][1][j] + dp[i][2][j]) % MOD;
    }
    
    int t, n, ans;
    cin >> t;
    while(t--) {
        cin >> n;
        ans = sum[n] - dp[n][1][2] - dp[n][2][1];
        while(ans < 0) ans += MOD;
        cout << ans % MOD << endl;
    }
    
    return 0;
}