// https://neoj.sprout.tw/problem/69/
#pragma GCC optimize ("O2")
#pragma GCC optimize ("O3")
#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define rep(v, i, n, s) for(int v = i; s > 0 ? v < n : v > n; v += s)
#define pb push_back
#define ll long long
#define endl '\n'
#define pii pair<long,long>
#define mpii(a, b) make_pair(a, b)
#define ff first
#define ss second
#define all(x) x.begin(),x.end()
#define boost ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define debug(x) cerr<<#x<<":"<<x<<endl;
#define debuq(x) cerr<<"debug:"<<#x<<endl;
#define input freopen("input.in", "r", stdin)

const int MAXN = 10000;
pii mh[MAXN];
ll oh[MAXN];
ll t, n, k, m, sum, midx, oidx, pass;

bool sortComp(pii a, pii b) {
    return a.ff >= b.ff && a.ss <= b.ss;
}

// bool comp(int a) {
//     return l[a].ff > l[a].ss;
// }

// int binary_search(int left = -1, int right = n) {
//     if(left == right - 1) return right;
//     int mid = (left + right) / 2;
//     if(comp(mid)) {
//         return binary_search(mid, right);
//     }else{
//         return binary_search(left, mid);
//     }
// }

int main() {
    // input; // annotate before submitting
    boost;
    
    cin >> t;
    while(t--) {
        sum = 0;
        cin >> n >> k;
        rep(i, 0, n, 1) {
            cin >> mh[i].ff >> mh[i].ss;
            if(mh[i].ss > 0) sum++;
        }
        rep(i, 0, n, 1) {
            cin >> oh[i];
        }
        sort(oh, oh + n, greater<int>());
        m = 0;
        while(1) {
            sort(mh, mh + n, greater<pii>());
            midx = 0;
            oidx = 0;
            pass = 0;
            while(oidx != n && midx != n) {
                if(mh[midx].ff > oh[oidx]) {
                    pass++;
                    oidx++;
                    midx++;
                }else{
                    oidx++;
                }
            } 
            if(pass >= k) {
                cout << m << endl;
                break;
            }else if(sum < k){
                cout << -1 << endl;
                break;
            }else{
                m++;
                rep(i, 0, n, 1) {
                    mh[i].ff+=mh[i].ss;
                }
            }
        }
    }
    
    return 0;
}