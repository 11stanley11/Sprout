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
#define mpii(a, b) make_pair(a, b)
#define ff first
#define ss second
#define all(x) x.begin(),x.end()
#define boost ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define debug(x) cerr<<#x<<":"<<x<<endl;
#define debuq(x) cerr<<"debug:"<<#x<<endl;
#define input freopen("../input.in", "r", stdin)

const int MOD = 1e15 + 7;
const int BASE = 257;
vector<int> arr;

int rolling_hash(const string &str) {
    int res = 0;
    int power = 1;
    rep(i, 0, str.size(), 1) {
        res = (res + str[i] * power) % MOD;
        power = (power * BASE) % MOD;
    }
    return res;
}

int count_occurrences(int v) {
    auto low = lower_bound(arr.begin(), arr.end(), v);
    auto high = upper_bound(arr.begin(), arr.end(), v);
    return high - low;
}

signed main() {
    input; // annotate before submitting
    boost;
    
    int n, m;
    string s;
    cin >> n >> m;
    while (n--) {
        cin >> s;
        arr.pb(rolling_hash(s));
    }
    sort(all(arr));
    while (m--) {
        cin >> s;
        cout << count_occurrences(rolling_hash(s)) << endl;
    }
    
    return 0;
}