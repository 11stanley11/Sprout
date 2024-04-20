https://neoj.sprout.tw/problem/789/
#pragma GCC optimize ("O3")
#pragma GCC optimize ("O2")
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

const int MAXN = 1e5;
int nums[MAXN];
int tmp[MAXN];

void dc(int left, int right) { //[l, r)
    if(right - left <= 2) return;
    copy(nums + left, nums + right, tmp + left);
    int j = left;
    rep(i, left + 1, right, 2) nums[j++] = tmp[i];
    rep(i, left, right, 2) nums[j++] = tmp[i];
    int mid = ceil((left + right) / 2);
    dc(left, mid);
    dc(mid, right);
}

int main() {
    // input; // annotate before submitting
    boost;
    
    int n = 0;
    cin >> n;
    rep(i, 0, n, 1) nums[i] = i+1;
    dc(0, n);
    rep(i, 0, n, 1) cout << nums[i] << " ";
    // while(n < MAXN) { // judge
    //     rep(i, 0, n, 1) nums[i] = i+1;
    //     dc(0, n);
    //     // rep(i, 0, n, 1) cout << nums[i] << " ";
    //     bool flag = false;
    //     rep(i, 2, n, 1) {
    //         if(nums[i] - nums[i-1] == nums[i-1] - nums[i-2]) {
    //             flag = true;
    //             break;
    //         }
    //     } 
    //     if(flag) {
    //         rep(i, 0, n, 1) cout << nums[i] << " ";
    //     }else{
    //         cout << n << " passed." << endl;
    //     }
    //     n++;
    // }
    return 0;
}