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

vector<int> multiply_matrix_vector(const vector<vector<int>>& A, const vector<int>& R) {
    int n = A.size();
    int m = R.size();

    vector<int> res(n, 0);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            res[i] += A[i][j] * R[j];
        }
    }

    return res;
}

// Function to generate a random vector
vector<int> generate_random_vector(int size) {
    vector<int> R(size);
    for (int i = 0; i < size; i++) {
        R[i] = rand() % 100; // Generate random numbers in range [0, 100)
    }
    return R;
}

signed main() {
    input; // annotate before submitting
    boost;
    
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> A(n, vector<int>(m));
    vector<vector<int>> B(m, vector<int>(k));
    vector<vector<int>> C(n, vector<int>(k));
    rep(i, 0, n, 1) rep(j, 0, m, 1) cin >> A[i][j];
    rep(i, 0, m, 1) rep(j, 0, k, 1) cin >> B[i][j];
    rep(i, 0, n, 1) rep(j, 0, k, 1) cin >> C[i][j];

    vector<int> R = generate_random_vector(k);
    
    vector<int> res = multiply_matrix_vector(A, multiply_matrix_vector(B, R));
    vector<int> res2 = multiply_matrix_vector(C, R);

    if(res == res2) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}