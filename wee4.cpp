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

int n;
vector<bool> use(n, false);
vector<int> now;

// 遞迴排列
void f() {
    if(now.size() == n) { //output now
        rep(i, 0, n, 1) {
            cout << now[i] << " ";
        }
        cout << endl;
        return;
    }
    rep(i, 0, n, 1) {
        if(use[i]) continue;
        use[i] = true;
        now.pb(i);
        f();
        now.pop_back();
        use[i] = false;
    }
}

// 枚舉子集
// 遞迴 (只拿比上一個元素更大的元素)
void fp(int lst = 0) {
    if(now.size() == n) { //output now
        rep(i, 0, n, 1) {
            cout << now[i] << " ";
        }
        cout << endl;
        return;
    }
    rep(i, lst, n, 1) {
        if(use[i]) continue;
        use[i] = true;
        now.pb(i);
        fp(i);
        now.pop_back();
        use[i] = false;
    }
}

// 位元運算
/*
rep(i, 0, (1 << n), 1) {
    rep(j, 0, n, 1) {
        if(1 << j & i) cout << j << " ";
    }
    cout << endl;
}
*/

// STL's func (next_permutation)
/*
vector<int> now(n);
iota(all(now), 1)
do{ // output now
    rep(i, 0, n, 1) {
        cout << now[i] << " ";
    }
    cout << endl;
}
while(next_permutaion(all(now)));
*/

// STL's 二分搜
// lower_bound(l, r, val, comp) => return 第一個>=val的位置
// upper_bound(l, r, val, comp) => return 第一個>val的位置
// comp => less<> or greater<>
// less<> 遞增排序 (預設)
// greater<> 遞減排序 lower_bound變<= upper_bound變<
// 通式 lower_bound找第一個1 f(i) = {0, if comp(vi, val); 1, otherwise}
// 通式 upper_bound找第一個0 f(i) = {1, if comp(val, vi); 0, otherwise}


int main() {
    input; // annotate before submitting
    boost;
    
    
    
    return 0;
}