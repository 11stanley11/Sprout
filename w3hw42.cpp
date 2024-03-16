// https://neoj.sprout.tw/problem/42/
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

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1}; 
int yx[1000][1000];
int n, h, w, sum;
char c;

bool checkBoarder(int y, int x) {
    if(0 <= y && y < h && 0 <= x && x < w) return true;
    else return false;
}

void dfs(int y, int x) {
    if(checkBoarder(y, x) && yx[y][x] == 1) {
        yx[y][x] = 0;
        rep(i, 0, 4, 1) {
            dfs(y + dy[i], x + dx[i]);
        }
    }
}

int main() {
    // input; // annotate before submitting
    boost;
    
    cin >> n;
    while(n--) {
        cin >> h >> w;
        rep(i, 0, h, 1) rep(j, 0, w, 1) {
            cin >> c;
            if(c == '.') yx[i][j] = 1;
            else yx[i][j] = 0;
        }
        sum = 0;
        rep(i, 0, h, 1) rep(j, 0, w, 1) {
            if(yx[i][j]) {
                sum++;
                dfs(i, j);
            }
        }
        cout << sum << endl;
    }
    
    
    return 0;
}