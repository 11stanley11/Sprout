// https://neoj.sprout.tw/problem/124/
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

int yx[1024][1024];
int idx = 1;

void Report(int x1, int y1, int x2, int y2, int x3, int y3) {
    yx[x1-1][y1-1] = idx;
    yx[x2-1][y2-1] = idx;
    yx[x3-1][y3-1] = idx;
    idx++;
    cout << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << ' ' << x3 << ' ' << y3 << endl;
}

void solve(int n, int y, int x, pii ini = {0,0}) {
    if(n == 1) return;
    int nn = n / 2; y--; x--; 
    pii pt; vector<pii> l;
    rep(i, 0, 2, 1) rep(j, 0, 2, 1){
        if(nn*i <= y && y < nn*(i+1) && nn*j <= x && x < nn*(j+1)) {
            solve(nn, y - nn*i + 1, x - nn*j + 1, {nn*i+ini.ff, nn*j+ini.ss});
        }else{
            pt = {nn+i, nn+j};
            l.pb({pt.ff+ini.ff, pt.ss+ini.ss});
            solve(nn, pt.ff - nn*i, pt.ss - nn*j, {nn*i+ini.ff, nn*j+ini.ss});
        }
    }
    Report(l[0].ff, l[0].ss, l[1].ff, l[1].ss, l[2].ff, l[2].ss);
}

int main() {
    // input; // annotate before submitting
    
    memset(yx, 0, sizeof(yx));
    solve(8, 2, 2);
    rep(i, 0, 8, 1) {
        rep(j, 0, 8, 1) {
            cout << yx[i][j] << " ";
        }
        cout << endl;   
    }
    return 0;
}