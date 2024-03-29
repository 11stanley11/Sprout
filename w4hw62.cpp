// https://neoj.sprout.tw/problem/62/
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

const int N = 3;
const vector<bool> nums(N*N, true);
bool ans, invalid;
vector<vector<int>> grid(N*N, vector<int>(N*N));
vector<vector<bool>> rowChoices(N*N, nums); // horizontal
vector<vector<bool>> colChoices(N*N, nums); // vertical
vector<vector<vector<bool>>> boxChoices(N, vector<vector<bool>>(N, nums));
vector<class Space> spaces;

struct Space {
    Space(int y, int x) : yx({y, x}) {}
    pii yx;
    vector<int> choices;
    vector<pii> conflictedSpaces;
    void set() {
        rep(i, 0, N*N, 1) {
            if(rowChoices[yx.ff][i] && colChoices[yx.ss][i] && boxChoices[yx.ff/N][yx.ss/N][i]) {
                choices.pb(i+1);
            }
        }
        for(auto s : spaces) {
            if(s.yx != yx && (s.yx.ff == yx.ff || s.yx.ss == yx.ss || (s.yx.ff/N == yx.ff/N && s.yx.ss/N == yx.ss/N))) {
                conflictedSpaces.pb(s.yx);
            }
        }
    }
};

void solve(Space s, int depth = 0) {
    if(ans) return ;
    // cout << depth << s.choices.size() << s.yx.ff << s.yx.ss;
    for(auto c : s.choices) {
        bool flag = true;
        for(auto cs : s.conflictedSpaces) {
            if(grid[cs.ff][cs.ss] == c) {
                flag = false;
                break;
            }
        }
        if(flag) {
            grid[s.yx.ff][s.yx.ss] = c;
            if(depth == spaces.size() - 1) {
                ans = true;
                return ;
            }
            solve(spaces[depth+1], depth+1);
            if(ans) return ;
            grid[s.yx.ff][s.yx.ss] = 0;
        }
    }
}

int main() {
    // input; // annotate before submitting
    boost;
    
    int t;
    char c;
    cin >> t;
    while(t--) {
        spaces = vector<class Space>();
        fill(all(rowChoices), nums);
        fill(all(colChoices), nums);
        fill(all(boxChoices), vector<vector<bool>>(N, nums));
        invalid = false;
        rep(i, 0, N*N, 1) rep(j, 0 ,N*N, 1) {
            cin >> c;
            if(c=='.') {
                grid[i][j] = 0;
                spaces.pb(Space(i, j));
            }else{
                grid[i][j] = int(c)-'0';
                if(!(rowChoices[i][int(c)-'0'-1] && colChoices[j][int(c)-'0'-1] && boxChoices[i/N][j/N][int(c)-'0'-1])) {
                    invalid = true;
                }
                rowChoices[i][int(c)-'0'-1] = false;
                colChoices[j][int(c)-'0'-1] = false;
                boxChoices[i/N][j/N][int(c)-'0'-1] = false;
            }   
        }
        if(invalid) {
            cout << "No solution." << endl;
            continue;
        }
        rep(i, 0, spaces.size(), 1) {
            spaces[i].set();
        }
        ans = false;
        solve(spaces[0]);
        if(ans) {
            rep(i, 0, N*N, 1) rep(j, 0, N*N, 1) {
                cout << grid[i][j];
            }
        }
        else cout << "No solution.";
        cout << endl;
    }
    return 0;
}