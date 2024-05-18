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

const int MAXN = 1e5 + 5;
const int INF = 1e9;
int weight[MAXN];
int dp[MAXN];
int val[105];

signed main() {
    // input; // annotate before submitting
    boost;
    
    int t, n, m;
    cin >> t;
    while(t--){
        cin >> n >> m;
        rep(i, 1, n+1, 1) {
            cin >> weight[i] >> val[i];
        }
        memset(dp, INF, sizeof(dp));
        dp[0] = 0;
        for(int i=1;i<=n;i++){
            for(int j=10000;j>=val[i];j--){
                dp[j] = min(dp[j],dp[j-val[i]]+weight[i]);
            }
        }
        int ans = 0;
        rep(i, 0, 10001, 1) {
            if(dp[i] <= m && i > ans) ans = i;
        }
        cout << ans << endl;
    }
    
    return 0;
}