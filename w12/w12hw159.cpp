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

const int MAXN = 105;
bool dp[20005];

signed main() {
    // input; // annotate before submitting
    boost;
    
    int t, n, m, val[MAXN], num[MAXN];
    cin >> t;
    while(t--) {
        cin >> n >> m;
        rep(i, 0, n, 1) cin >> val[i] >> num[i];
    
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;

        rep(i, 0, n, 1) {
            rep(k, 0, val[i], 1) {
                int left = num[i];
                rep(j, k + val[i], m + 1, val[i]) {
                    if(dp[j] != 0) left = num[i];
                    else if(left > 0 && dp[j - val[i]]){
                        left--;
                        dp[j] = 1;
                    }
                }
            }
        }

        if(dp[m]) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    
    return 0;
}