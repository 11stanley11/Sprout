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
#define input freopen("../input.in", "r", stdin)

const int MAXN = 1e5 + 5;
int dp[MAXN];

signed main() {
    // input; // annotate before submitting
    boost;
    
    int t, n, k, c, ans, val[100005];
    cin >> t;
    while(t--) {
        cin >> n >> k >> c;
        rep(i, 1, n + 1, 1) cin >> val[i];

        memset(dp,0,sizeof(dp));
        deque<pair<int,int>> deq;
        deq.push_back(make_pair(val[1]+c,1));
        dp[1] = val[1];

        rep(i, 2, n + 1, 1) {
            while(!deq.empty() && deq.front().second < i - k) deq.pop_front();
            dp[i] = val[i] - c * i + max(c * i, deq.front().first);
            while(!deq.empty() && deq.back().first <= dp[i]+c*i) deq.pop_back();
            deq.push_back(make_pair(dp[i]+c*i,i));
        }

        ans = 0;
        rep(i, 1, n + 1, 1) ans = max(ans, dp[i]);
        cout << ans << endl;
    }
    
    return 0;
}