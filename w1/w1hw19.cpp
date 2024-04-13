// https://neoj.sprout.tw/problem/19/
#include <bits/stdc++.h>
#define boost ios::sync_with_stdio(0);cin.tie(0)
#define endl '\n'
#define ll long long
#define pii pair<int, int>
#define mpii(a, b) make_pair(a, b) 

using namespace std; 

int main() {
    boost;

    int t, n, ins, idx;
    cin >> t;
    while(t--) {
        idx = 0;
        cin >> n;
        queue<int> q;
        stack<int> wait;
        for(int i = 0; i < n; i++) {
            cin >> ins;
            q.push(ins);
        }
        while(true) {
            if(!wait.empty() && wait.top() == q.front()) {
                q.pop();
                wait.pop();
                continue;
            }
            if(q.empty()) {
                cout << "Yes" << endl;
                break;
            }else if(q.front() < idx || idx > n) {
                cout << "No" << endl;
                break;
            }
            idx++;
            if(idx == q.front()) {
                q.pop();
            }else{
                wait.push(idx);
            }
        }
    }

    return 0;
}