// https://neoj.sprout.tw/problem/59/
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

int t, cmd, n;
priority_queue<int, vector<int>, greater<int>> pq;

int main() {
    // input; // annotate before submitting
    boost;
    
    cin >> t;
    while(t--) {
        cin >> cmd;
        if(cmd == 1) {
            cin >> n;
            pq.push(n);
        }else if(!pq.empty()){
            cout << pq.top() << endl;
            pq.pop();
        }else{
            cout << "empty!" << endl;
        }
    }
    
    return 0;
}