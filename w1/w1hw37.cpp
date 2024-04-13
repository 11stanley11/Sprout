// 
#include <bits/stdc++.h>
#define boost ios::sync_with_stdio(0);cin.tie(0)
#define endl '\n'
#define ll long long
#define pii pair<int, int>
#define mpii(a, b) make_pair(a, b) 

using namespace std; 

queue<int> qu;

int main() {
    boost;
    
    int t, cmd, n;
    cin >> t;
    while(t--) {
        cin >> cmd;
        if(cmd == 1) {
            cin >> n;
            qu.push(n);
        }else if(!qu.empty()) {
            cout << qu.front() <<endl;
            qu.pop();
        }else{
            cout << "empty!" << endl;
        }   
    }
    
    return 0;
}