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
#define INF 1e16

const int MAXN = 2e5 + 5;
vector<pii> adj[MAXN];
vector<int> dis_s(MAXN);
vector<int> dis_e(MAXN);
priority_queue<pii, vector<pii>, greater<pii>> pq;

signed main() {
    // input; // annotate before submitting
    boost;
    
    int n, m, q, a, b, w, idx;
    pii cur;
    cin >> n >> m >> q;
    while(m--) {
        cin >> a >> b >> w;
        a--; b--;
        adj[a].pb({w, b});
        adj[b].pb({-w, a});
    }

    fill(dis_s.begin(), dis_s.begin() + n, INF);
    idx = 0; dis_s[0] = 0;
    pq.push({dis_s[0], idx});
    while(!pq.empty()) {
        cur = pq.top(); pq.pop();
        if(cur.ff != dis_s[cur.ss]) continue;
        rep(i, 0, adj[cur.ss].size(), 1) {
            if(adj[cur.ss][i].ff < 0) continue;
            if(dis_s[adj[cur.ss][i].ss] > adj[cur.ss][i].ff + cur.ff) {
                dis_s[adj[cur.ss][i].ss] = adj[cur.ss][i].ff + cur.ff;
                pq.push({dis_s[adj[cur.ss][i].ss], adj[cur.ss][i].ss});
            }
        }
    }

    fill(dis_e.begin(), dis_e.begin() + n, INF);
    idx = n - 1; dis_e[n - 1] = 0;
    pq.push({dis_e[n - 1], idx});
    while(!pq.empty()) {
        cur = pq.top(); pq.pop();
        if(cur.ff != dis_e[cur.ss]) continue;
        rep(i, 0, adj[cur.ss].size(), 1) {
            if(adj[cur.ss][i].ff > 0) continue;
            if(dis_e[adj[cur.ss][i].ss] > -adj[cur.ss][i].ff + cur.ff) {
                dis_e[adj[cur.ss][i].ss] = -adj[cur.ss][i].ff + cur.ff;
                pq.push({dis_e[adj[cur.ss][i].ss], adj[cur.ss][i].ss});
            }
        }
    }

    // rep(i, 0, n, 1) cout << dis_s[i] << " ";
    // cout << endl;
    // rep(i, 0, n, 1) cout << dis_e[i] << " ";
    // cout << endl;

    while(q--) {
        cin >> a >> b;
        a--; b--;
        cout << min(dis_s[n-1] ,dis_s[a] + dis_e[b] + 1) << endl;
    }

    return 0;
}