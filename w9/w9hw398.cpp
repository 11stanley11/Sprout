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

const double eps = 1e-10;
const int MAXN = 501;
double pts[MAXN];

int judge(int n) { // 硬爆
    int cnt = 0;
    rep(i, 0, n, 1) rep(j, 0, n, 1) {
        double goal = pts[i] + pts[j];
        rep(k, 0, n, 1) {
            if(fabs(pts[k] - goal) < eps) {
                cout << pts[i] << " " << pts[j] << " " << pts[k] << endl;
                cnt++;
            }
        }
    }
    return cnt;
}

signed main() {
    input; // annotate before submitting
    boost;
    
    int n, cnt = 0;
    double goal, tmp = -1;
    cin >> n;
    rep(i, 0, n, 1) {
        cin >> pts[i];
    }
    sort(pts, pts + n);
    rep(i, 0, n, 1) rep(j, i, n, 1) {
        goal = pts[i] + pts[j];
        rep(k, j, n, 1) {
            if(fabs(pts[k] - goal) < eps) {
                cnt += pts[i] == pts[j] ? 1 : 2; 
                cout << pts[i] << " " << pts[j] << " " << pts[k] << endl;
            }
            if(pts[k] - goal > eps) break;
        }
    } 

    cout << cnt << endl;
    cout << judge(n) << endl; // 結論 硬爆

    return 0;
}           