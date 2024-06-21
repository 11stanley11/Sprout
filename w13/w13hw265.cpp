// https://medium.com/@c.s.fangyolk/kmp-%E6%BC%94%E7%AE%97%E6%B3%95-%E5%BE%9E%E8%87%AA%E5%AD%B8%E5%88%B0%E6%94%BE%E6%A3%84-2-94dda22f80b2
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

vector<int> kmp_lps(string &pattern) { 
    vector<int> lps(pattern.size());
    int prev = 0;
    lps[0] = prev;
    rep(i, 1, pattern.size(), 1) {
        while(prev > 0 && pattern[i] != pattern[prev]) {
            prev = lps[prev - 1];
        }
        if(pattern[i] == pattern[prev]) {
            prev++;
        }
        lps[i] = prev;
    }
    return lps;
}

vector<int> kmp_search(string text, string pattern) {
    vector<int> res;
    vector<int> lps = kmp_lps(pattern);
    int prev = 0;
    rep(i, 0, text.size(), 1) {
        while(prev > 0 && text[i] != pattern[prev]) {
            prev = lps[prev - 1];
        }
        if(text[i] == pattern[prev]) {
            prev++;
        }
        if(prev == pattern.size()) {
            res.pb(i - pattern.size() + 1);
            prev = lps[prev - 1];
        }
    }
    return res;
}

signed main() {
    input; // annotate before submitting
    boost;

    string text, pattern;
    cin >> pattern >> text;
    vector<int> cor = kmp_search(text, pattern);
    rep(i, 0, cor.size(), 1) {
        if(i > 0) cout << " ";
        cout << cor[i];
    }
    cout << endl;

    return 0;
}