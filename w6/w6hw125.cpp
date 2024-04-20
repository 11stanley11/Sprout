// https://neoj.sprout.tw/problem/125/
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

const int mod = 10000019;
const int MAXN = 1e6 + 1;
vector<int> tmp;
int nums[MAXN];
int cnt = 0;

void dc(int left, int right) { // [l, r)
    if(right - left <= 1) return;
    int mid = (left + right) / 2;
    dc(left, mid);
    dc(mid, right);
    int lsum = 0;
    rep(i, left, mid, 1) lsum += nums[i];
    tmp = vector<int>();
    int j = mid;
    rep(i, left, mid, 1) {
        while(j < right && nums[i] > nums[j]) {
            cnt += nums[j] * (mid-i) + lsum;
            cnt %= mod;
            tmp.pb(nums[j++]);
        }
        lsum = lsum - nums[i];
        tmp.pb(nums[i]);
    }
    while(j < right) tmp.pb(nums[j++]);  
    copy(all(tmp), nums + left);
}

signed main() {
    // input; // annotate before submitting
    boost;
    
    int n;
    cin >> n;
    rep(i, 0, n, 1) {
        cin >> nums[i];
    }
    dc(0, n);
    cout << cnt % mod << endl;
    
    return 0;
}