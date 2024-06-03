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
#define piii pair<int,pair<int,int>>
#define mpii(a, b) make_pair(a, b)
#define ff first
#define ss second
#define all(x) x.begin(),x.end()
#define boost ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define debug(x) cerr<<#x<<":"<<x<<endl;
#define debuq(x) cerr<<"debug:"<<#x<<endl;
#define input freopen("../input.in", "r", stdin)
#define INF 1e16

const int MAXN = 1e2 + 2;
vector<pii> adj[MAXN];
vector<int> dis(MAXN);
priority_queue<pii, vector<pii>, greater<pii>> pq;

int dijkstra(int s, int e) {
    dis[s] = 0;
    pq.push({dis[s], s});
    while(!pq.empty()) {
        pii cur = pq.top();
        pq.pop();
        if(cur.ff > dis[cur.ss]) continue;
        for(auto edge : adj[cur.ss]) {
            if(dis[edge.ff] > cur.ff + edge.ss) {
                dis[edge.ff] = cur.ff + edge.ss;
                pq.push({dis[edge.ff], edge.ff});
            }
        }
    }

    return dis[e];
}


signed main() {
    // input; // annotate before submitting
    boost;
    
    int t, n, m, s, e, f, a, b, c, d, cp, w;    
    cin >> t;
    while(t--) {
        cin >> n >> m >> s >> e >> f;
        s--; e--;

        fill(dis.begin(), dis.begin() + n, INF);
        rep(i, 0, n, 1) adj[i].clear();

        while(m--) {
            cin >> a >> b >> c >> d >> cp;
            a--; b--;
            w = f > d ? c * d + cp * (f - d) : c * f;
            adj[a].pb({b, w});
        }

        cout << dijkstra(s, e) << endl;
    }
    
    return 0;
}