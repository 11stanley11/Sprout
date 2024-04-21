// https://neoj.sprout.tw/problem/141/
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

const int MAXN = 1e5;
int nums[MAXN];
int dp[MAXN];

signed main() {
    // input; // annotate before submitting
    boost;
    
    int t, n;
    cin >> t;
    while(t--) {
        cin >> n;
        rep(i, 0, n, 1) {
            cin >> nums[i];
        }
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        rep(i, 2, n, 1) {
            dp[i] = max(dp[i-1], dp[i-2] + nums[i]);
        }
        cout << dp[n-1] << endl;
    }
    
    return 0;
}