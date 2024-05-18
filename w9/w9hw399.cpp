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

const int MAXN = 1e3 + 3;
vector<pii> dots(MAXN);
vector<int> lens;

signed main() {
    boost;
    input;
    
    int n, dis, cnt = 1, tmp, ans = 0;
    cin >> n;
    rep(i, 0, n, 1) {
        cin >> dots[i].ff >> dots[i].ss;
    }
    rep(i, 0, n, 1) rep(j, i+1, n, 1){
        dis = (dots[i].ff - dots[j].ff) * (dots[i].ff - dots[j].ff) + (dots[i].ss - dots[j].ss) * (dots[i].ss - dots[j].ss);
        lens.pb(dis);
    }
    sort(all(lens));

    if(!lens.empty()) {
        tmp = lens[0];
        rep(i, 1, lens.size(), 1) {
            if(lens[i] == tmp) cnt++;
            else{
                ans += cnt * (cnt - 1) / 2;
                cnt = 1;
            }
            tmp = lens[i];
        }
        ans += cnt * (cnt - 1) / 2;
    }

    cout << ans << endl;

    return 0;
}
