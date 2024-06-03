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
#define INF INT_MAX

const int MAXN = 2e5 + 5;
vector<pii> adj[MAXN];
int dis[MAXN];
int par[MAXN];
bool in_MST[MAXN];
priority_queue<pii, vector<pii>, greater<pii>> pq;

signed main() {
    boost;
    // input;
    
    int n, m, u, v, w;
    ll sum = 0;
    cin >> n >> m;
    
    fill(dis, dis + n, INF);
    fill(in_MST, in_MST + n, false);
    
    while(m--) {
        cin >> u >> v >> w;
        u--; v--;
        adj[u].pb({v, w});
        adj[v].pb({u, w});
    }
    
    dis[0] = 0;
    par[0] = -1;
    pq.push({0, 0});
    
    while(!pq.empty()) {
        int cur = pq.top().ss;
        pq.pop();
        if(in_MST[cur]) continue;
        in_MST[cur] = true;
        sum += dis[cur];
        rep(i, 0, adj[cur].size(), 1) {
            if(!in_MST[adj[cur][i].ff] && adj[cur][i].ss < dis[adj[cur][i].ff]) {
                dis[adj[cur][i].ff] = adj[cur][i].ss;
                par[adj[cur][i].ff] = cur;
                pq.push({dis[adj[cur][i].ff], adj[cur][i].ff});
            }
        }
    }
    
    cout << sum << endl;

    return 0;
}


