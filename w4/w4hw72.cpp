// https://neoj.sprout.tw/problem/72/
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
#define input freopen("input.in", "r", stdin)

double a[10];
double b[10];
double c[10];
double func(double t, int idx) {
    return a[idx] * (t - b[idx]) * (t - b[idx]) + c[idx];
}

int main() {
    // input; // annotate before submitting
    boost;
    
    double maxi, mini, cur;
    int t, n;
    cin >> t;
    while(t--) {
        mini = INT_MAX;
        cin >> n;
        rep(i, 0, n, 1) {
            cin >> a[i] >> b[i] >> c[i];
        }
        double left = 0.0, right = 300.0, lv, rv, nl, nr;
        int cnt = 0;
        while(cnt < 10000) {
            nl = (left * 2 + right) / 3;
            nr = (left + right * 2) / 3;
            lv = 0.0; rv = 0.0;
            rep(i, 0, n, 1) lv = max(lv, func(nl, i));
            rep(i, 0, n, 1) rv = max(rv, func(nr, i));
            if(lv > rv) left = nl;
            else right = nr;
            cnt++;
        }
        cout << setprecision(10) << lv << endl;
    }
    
    return 0;
}