// https://neoj.sprout.tw/problem/795/
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
vector<pii> xy, tmp, l, r;
vector<int> idx;

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
    int li = 1, ri = 1;
    rep(i, left, right + 1, 1) {
        if(abs(xy[i].ff - mid_x) <= mini) {
            if(xy[i].ff >= mid_x) { // on the right
                r.pb(xy[i]);
                idx.pb(li);
                ri++;
            }else{ // on the left
                l.pb(xy[i]);
                idx.pb(-ri);
                li++;
            }
        }
    }
    int len = idx.size(), llen = l.size(), rlen = r.size();
    li = 0; ri = 0;
    rep(i, 0, len, 1) {
        if(idx[i] > 0) { // on the right
            rep(j, abs(idx[i])-1, llen, 1) {
                mini = min(mini, cal(r[ri], l[j]));
                if(abs(r[ri].ss - l[j].ss) > mini) break;
            }
            ri++;
        }else{ // on the left
            rep(j, abs(idx[i])-1, rlen, 1) {
                mini = min(mini, cal(l[li], r[j]));
                if(abs(l[li].ss - r[j].ss) > mini) break;
            }
            li++;
        }
    }
    idx.clear();
    l.clear();
    r.clear();
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
        sort(all(xy));
        cout << dc(0, n - 1) << endl;
    }
    return 0;
}