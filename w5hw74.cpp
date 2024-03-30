// https://neoj.sprout.tw/problem/74/
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

const int MAXN = int(1e6) + 3;
ll h[MAXN];

int main() {
    // input; // annotate before submitting
    boost;
    
    ll t, n, mini, len, idx, maxi, next;
    bool flag;
    h[0] = static_cast<long long>(pow(2, 31)) + 1;
    h[1] = 0;
    cin >> t;
    while(t--) {
        cin >> n;
        n+=3;
        rep(i, 2, n-1, 1) {
            cin >> h[i];
        }
        h[n-1] = 0;
        idx = 0;
        len = -1;
        flag = false;
        while(1) {
            mini = h[idx];
            maxi = 0;
            rep(j, idx+1, n, 1) {
                // cout << mini << " " << h[j] << " " << maxi <<endl;
                if(mini != h[idx] && h[j] > mini && h[j] > maxi) {
                    maxi = h[j];
                    next = j;
                }
                if(mini != h[idx] && maxi != 0 && maxi > h[j]) {
                    idx = next;
                    // cout << idx << endl;
                    len += 2;
                    break;
                }else mini = min(mini, h[j]);
                if(j == n-1) flag = true;
            }
            if(flag) break;
        }
        if(len > -1) cout << len << endl;
        else cout << 1 << endl;
    }
    
    return 0;
}