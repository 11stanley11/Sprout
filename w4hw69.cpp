// https://neoj.sprout.tw/problem/69/
#pragma GCC optimize ("O2")
#pragma GCC optimize ("O3")
#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define rep(v, i, n, s) for(int v = i; s > 0 ? v < n : v > n; v += s)
#define pb push_back
#define int long long
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
vector<int> mh0;
int oh[MAXN];

int binary_search(int value, int left, int right) {
    if(left == right - 1) return right;
    int mid = (left + right) / 2;
    if(oh[mid] >= value) {
        return binary_search(value, mid, right);
    }else{
        return binary_search(value, left, mid);
    }
}

int32_t main() {
    // input; // annotate before submitting
    boost;
    
    int t, n, k, m, lst, pass, h, v, cur, mhlen, ohlen;
    cin >> t;
    while(t--) {
        mh0 = vector<int>();
        cin >> n >> k;
        rep(i, 0, n, 1) {
            cin >> h >> v;
            if(v > 0) {
                mh[i] = {h, v};
            }else{
                mh0.pb(h);
                mh[i] = {-1, 0};
            } 
        }
        rep(i, 0, n, 1) {
            cin >> oh[i];
        }
        mhlen = n - mh0.size();
        ohlen = n;
        oh[n] = -1;
        sort(mh, mh + n, greater<pii>());
        sort(all(mh0), greater<int>());
        sort(oh, oh + n + 1, greater<int>());
        mh[mhlen] = {-1, 0};
        lst = -1;
        rep(i, 0, mh0.size(), 1) {
            if(lst >= n) {
                ohlen = n - i;
                break;
            }
            lst = binary_search(mh0[i], lst, n+1);
            if(lst >= n) {
                ohlen = n - i;
                break;
            }
            oh[lst] = -1;
            // cout << lst;
            lst++;
            k--;
        }
        sort(oh, oh + n + 1, greater<int>());
        m = 0;
        if(mhlen < k) {
            cout << -1 << endl;   
            continue;    
        }
        while(1) {
            sort(mh, mh + mhlen, greater<pii>());
            pass = 0;
            lst = -1;
            rep(i, 0, mhlen, 1) {
                if(lst >= ohlen) break;
                lst = binary_search(mh[i].ff, lst, ohlen + 1);
                if(lst >= ohlen) break;
                lst++;
                pass = i + 1;
            }
            if(pass >= k) {
                cout << m << endl;
                // rep(i, 0, mhlen, 1) {
                //     cout << mh[i].ff;
                // }
                break;
            }else{
                m++;
                rep(i, 0, mhlen, 1) {
                    mh[i].ff+=mh[i].ss;
                }
            }
        }
    }
    
    return 0;
}