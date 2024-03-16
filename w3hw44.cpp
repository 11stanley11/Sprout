// https://neoj.sprout.tw/problem/44/
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

struct Point {
    Point(int y, int x): y(y), x(x) {}
    int y;
    int x;
};

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
int t, n, m, curLayer, ans;
Point start = Point(0, 0);
Point cur = Point(0, 0);
queue<Point> q;
queue<int> layers;
int visited[100][100];
int yx[100][100];
char c;

void bfs() {
    ans = 0;
    q.push(start);
    layers.push(0);
    visited[start.y][start.x] = 1;
    while(!q.empty()) {
        cur = q.front();
        curLayer = layers.front();
        q.pop();
        layers.pop();
        if(yx[cur.y][cur.x] == 2) {ans = curLayer; break;}
        rep(i, 0, 4, 1) {
            if(yx[cur.y + dy[i]][cur.x + dx[i]] == 1 || visited[cur.y + dy[i]][cur.x + dx[i]]) continue;
            q.push(Point(cur.y + dy[i], cur.x + dx[i]));
            layers.push(curLayer + 1);
            visited[cur.y + dy[i]][cur.x + dx[i]] = 1;
        }
    }
    while(!q.empty() && !layers.empty()) {
        q.pop();
        layers.pop();
    }
}

int main() {
    // input; // annotate before submitting
    boost;
    
    cin >> t;
    while(t--) {
        cin >> n >> m;
        rep(i, 0, n, 1) rep(j, 0, m, 1) {
            cin >> c;
            visited[i][j] = 0;
            if(c == 'K') {start = Point(i, j); yx[i][j] = 0;} // start
            else if(c == '.') yx[i][j] = 0; // floor
            else if(c == '@') yx[i][j] = 2; // destination
            else yx[i][j] = 1; //wall
        }
        bfs();
        if(ans) cout << ans << endl;
        else cout << "= =\"" << endl;
    }
    
    return 0;
}