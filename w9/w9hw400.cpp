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

int cross(pii a, pii b) {
    return a.ff * b.ss - a.ss * b.ff;
}

int dot(pii a, pii b) {
    return a.ff * b.ff + a.ss * b.ss;
}

pii vec_minuse(pii a, pii b) {
    return {b.ff - a.ff, b.ss - a.ss};
}

signed main() {
    input; // annotate before submitting
    boost;
    
    pii cur_v, prev_v, cur_p, prev_p;
    int n, cross_value, dot_value, l = 0, r = 0, b = 0;
    cin >> n;
    cin >> prev_p.ff >> prev_p.ss >> cur_p.ff >> cur_p.ss;
    cur_v = vec_minuse(prev_p, cur_p);
    prev_v = cur_v;
    prev_p = cur_p;
    rep(i, 2, n, 1) {
        cin >> cur_p.ff >> cur_p.ss;
        cur_v = vec_minuse(prev_p, cur_p);
        cross_value = cross(prev_v, cur_v);
        dot_value = dot(prev_v, cur_v);
        if(cross_value > 0) l++;
        else if(cross_value < 0) r++;
        else if(cross_value == 0 && dot_value < 0) b++;
        prev_v = cur_v;
        prev_p = cur_p;
    }
    
    cout << l << " " << r << " " << b << endl;

    return 0;
}