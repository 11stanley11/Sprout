// https://neoj.sprout.tw/problem/143/
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

const int MAXN = 101;
int arr[MAXN];
int sum[MAXN];
int dp[MAXN];

signed main() {
    input; // annotate before submitting
    boost;
    
    int t, n;
    cin >> t;
    while(t--) {
        cin >> n;
        rep(i, 0, n, 1) {
            cin >> arr[i];
        }

        rep(i, 0, n-1, 1) {
            sum[i] = arr[i] + arr[i+1];
        }

        dp[2] =  
    }

    return 0;
}