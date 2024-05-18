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

pii vec_minuse(pii a, pii b) {
    return {a.ff - b.ff, a.ss - b.ss};
}

int cross(pii a, pii b) {
    return a.ff * b.ss - a.ss * b.ff;
}

int dot(pii a, pii b) {
    return a.ff * b.ff + a.ss * b.ss;
}

int sign(int a) {
    if(a==0) return 0;
    return a > 0 ? 1 : -1;
}

int ori(const pii &a, const pii &b, const pii &c) {
    return sign(cross(vec_minuse(b, a), vec_minuse(c, a)));
}

bool btw(pii p, pii a, pii b) {
    return ori(p, a, b) == 0 && sign(dot(vec_minuse(a, p), vec_minuse(b, p))) <= 0;
}

bool banana(const pii &a, const pii &b, const pii &c, const pii &d) {
    if(btw(a, c, d) || btw(b, c, d) || btw(c, a, b) || btw(d, a, b)) return true;
    return ori(a, b, c) * ori(a, b, d) < 0 && ori(c, d, a) * ori(c, d, b) < 0;
}

signed main() {
    input; // annotate before submitting
    boost;
    
    int t;
    pii p1, p2, q1, q2;
    cin >> t;
    while(t--) {
        cin >> p1.ff >> p1.ss >> p2.ff >> p2.ss >> q1.ff >> q1.ss >> q2.ff >> q2.ss;
        cout << (banana(p1, p2, q1, q2) ? "Yes" : "No") << endl;
    }

    return 0;
}