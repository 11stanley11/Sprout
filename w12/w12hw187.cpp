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
#define INF INT_MAX

const int MAXN = 16;
int dis[MAXN][MAXN];
int dp[MAXN][(1 << MAXN)];

signed main() {
    boost;
    // input;
    
    int t, n, w, s, ans;
    cin >> t;
    while(t--) {
        memset(dis, 0, sizeof(dis));
        cin >> n;
        rep(i, 0, n - 1, 1) {
            rep(j, i + 1, n, 1) {
                cin >> w;
                dis[i][j] = w;
                dis[j][i] = w;
            }
        }

        memset(dp, 0x3f3f3f3f, sizeof(dp));
        dp[0][1] = 0;
        rep(i, 0, (1 << n), 1) {
            rep(j, 0, n, 1) {
                if(!(i & (1 << j))) continue;
                rep(k, 0, n, 1) {
                    if(i & 1 << k) {
                        dp[j][i] = min(dp[j][i], dp[k][i - (1 << j)] + dis[j][k]);
                    }
                }
            }
        }

        ans = INF;
        rep(i, 0, n, 1) ans = min(ans, dp[i][(1 << n) - 1] + dis[i][0]);
        cout << ans << endl;
    }
    
    return 0;
}
