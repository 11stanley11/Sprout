// https://neoj.sprout.tw/problem/78/
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

int main() {
    // input; // annotate before submitting
    boost;
    
    int t, ans;
    int gift[6];
    cin >> t;
    while(t--) {
        ans = 0;
        rep(i, 0, 6, 1) {
            cin >> gift[i];
        }
        ans += gift[5];
        ans += gift[4]; gift[0] -= gift[4] * 11;
        ans += gift[3]; gift[1] -= gift[3] * 5; 
        ans += gift[2] / 4; gift[2] %= 4; if(gift[2] > 0) ans++;
        if(gift[2] == 1) {
            gift[1] -= 5; gift[0] -= 7;
        }else if(gift[2] == 2) {
            gift[1] -= 3; gift[0] -= 6;
        }else if(gift[2] == 3) {
            gift[1] -= 1; gift[0] -= 5;
        }
        if(gift[1] < 0) gift[0] += 4 * gift[1];
        if(gift[1] > 0) {
            ans += gift[1] / 9; gift[1] %= 9; 
            if(gift[1] > 0) {
                ans++; 
                gift[0] -= 36 - 4 * gift[1];
            }
        }
        if(gift[0] > 0) {
            ans += gift[0] / 36; gift[0] %= 36; 
            if(gift[0] > 0) ans++;
        }
        cout << ans << endl;
    }
    
    return 0;
}