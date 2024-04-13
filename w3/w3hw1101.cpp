// https://neoj.sprout.tw/problem/1101/
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

int t, n, m, a, b;
vector<int> line[int(1e5)];
int mate[int(1e5)];
bool flag;

void solve(int cur) {
    for(int i : line[cur]) {
        if(flag) break;
        if(mate[i] == 0) {
            mate[i] = mate[cur] * -1;
            solve(i);
        }else if(mate[i] == mate[cur]) {
            flag = true;
            break;
        }
    }
}

int main() {
    // input; // annotate before submitting
    boost;
    
    cin >> t;
    while(t--) {
        cin >> n >> m;
        rep(i, 0, n, 1) {
            line[i].clear();
            mate[i] = 0;
        }
        while(m--) {
            cin >> a >> b;
            line[a].pb(b);
            line[b].pb(a);            
        }
        mate[a] = 1;
        flag = false;
        solve(a);
        if(!flag) cout << "NORMAL." << endl;
        else cout << "RAINBOW." << endl;
    }
    
    return 0;
}