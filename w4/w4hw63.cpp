// https://neoj.sprout.tw/problem/63
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

int n, t;
int arr[13];
vector<int> now;
vector<bool> use(13, false);
void f(int lst = 0) {//output now
    if (now.size() == 6) {
        rep(i, 0, now.size(), 1) {
            cout << arr[now[i]];
            if(i != now.size() - 1) cout << " ";
        }
        cout << endl;
        return ;
    } 
    rep(i, lst, n, 1) {
        if(use[i]) continue;
        use[i] = true;
        now.pb(i);
        f(i);
        now.pop_back();
        use[i] = false;
    }
}

int main() {
    // input; // annotate before submitting
    boost;
    
    cin >> t;
    while(t--) {
        cin >> n;
        rep(i, 0, n, 1) {
            cin >> arr[i];
        }
        f();
    }
    
    return 0;
}