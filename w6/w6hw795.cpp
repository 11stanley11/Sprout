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

const int INF = __LONG_LONG_MAX__;
vector<pii> xy, tmp;

bool comp(pii a, pii b) {
    return a.ss < b.ss;
}

int cal(pii a, pii b) {
    return (a.ff - b.ff) * (a.ff - b.ff) + (a.ss - b.ss) * (a.ss - b.ss);
}

int dc(int left,int right) { // [l, r] 得是左閉又閉
    if(right == left) return INF;
    int mid = (left + right) / 2;
    int mid_x = xy[mid].ff;
    int mini = min(dc(left, mid), dc(mid+1, right));
    tmp.assign(right - left + 1, {0, 0});
    merge(xy.begin() + left, xy.begin() + mid + 1, xy.begin() + mid + 1, xy.begin() + right + 1, tmp.begin(), comp);
    rep(i, left, right + 1, 1) xy[i] = tmp[i-left];
    tmp.clear();
    rep(i, left, right + 1, 1) {
        if((xy[i].ff - mid_x) * (xy[i].ff - mid_x) <= mini) tmp.pb(xy[i]);
    }
    int len = tmp.size();
    rep(i, 0, len, 1) {
        rep(j, i + 1, len, 1) {
            mini = min(mini, cal(tmp[i], tmp[j])); // 放在y判斷前較保守，反正複雜度不變
            if(abs(tmp[j].ss - tmp[i].ss) > mini) break;
        }
    }
    return mini;
}

signed main() {
    // input; // annotate before submitting
    boost;
    
    int n;
    cin >> n;
    xy.assign(n, {0, 0});
    rep(i, 0, n, 1) {
        cin >> xy[i].ff >> xy[i].ss;
    }
    if(n==1) cout << 0;
    else{
        sort(xy.begin(), xy.begin() + n);
        cout << dc(0, n - 1) << endl;
    }
    return 0;
}