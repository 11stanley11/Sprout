#pragma GCC optimize("O2")
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define rep(v, i, n, s) for (int v = i; s > 0 ? v < n : v > n; v += s)
#define pb push_back
#define int long long
#define endl '\n'
#define pii pair<int, int>
#define mpii(a, b) make_pair(a, b)
#define ff first
#define ss second
#define all(x) x.begin(), x.end()
#define boost ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define debug(x) cerr << #x << ":" << x << endl
#define debuq(x) cerr << "debug:" << #x << endl
#define input freopen("../input.in", "r", stdin)
#define INF 1e16

const int MAXN = 2e5 + 5;
vector<pii> adj[MAXN];
vector<int> dis_s(MAXN);
vector<int> dis_e(MAXN);
priority_queue<pii, vector<pii>, greater<pii>> pq;

void dijkstra(int start, vector<int>& dist, bool forward) {
    fill(dist.begin(), dist.begin() + MAXN, INF);
    dist[start] = 0;
    pq.push({0, start});
    while (!pq.empty()) {
        pii cur = pq.top(); pq.pop();
        if (cur.ff != dist[cur.ss]) continue;
        for (auto edge : adj[cur.ss]) {
            if ((forward && edge.ff < 0) || (!forward && edge.ff > 0)) continue;
            int next_dist = dist[cur.ss] + abs(edge.ff);
            int next_node = edge.ss;
            if (dist[next_node] > next_dist) {
                dist[next_node] = next_dist;
                pq.push({next_dist, next_node});
            }
        }
    }
}

signed main() {
    boost;
    // input; // Uncomment if you have an input file

    int n, m, q, a, b, w;
    cin >> n >> m >> q;
    while (m--) {
        cin >> a >> b >> w;
        a--; b--; // Adjusting for zero-based indexing
        adj[a].pb({w, b});
        adj[b].pb({-w, a});
    }

    dijkstra(0, dis_s, true);      // Dijkstra from the source node 0
    dijkstra(n - 1, dis_e, false); // Dijkstra from the destination node n-1

    while (q--) {
        cin >> a >> b;
        a--; b--; // Adjusting for zero-based indexing
        cout << min(dis_s[n - 1], dis_s[a] + dis_e[b] + 1) << endl;
    }

    return 0;
}
