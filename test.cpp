#include <bits/stdc++.h>
#include <chrono>
#define boost ios::sync_with_stdio(0);cin.tie(0)
// #define endl '\n'
#define ll long long
#define pii pair<int, int>
#define mpii(a, b) make_pair(a, b) 

// using namespace std; 

int main() {
    // boost;
    
    int* ppl = new int[1000000];

    int repetitions = 1000000; // Number of repetitions for more accurate timing

    auto start = std::chrono::steady_clock::now();
    for (int i = 0; i < repetitions; ++i) {
        // Method to set all elements of ppl to -1 (e.g., using a loop or std::fill)
    }
    auto end = std::chrono::steady_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    std::cout << "Average time taken: " << duration.count() / repetitions << " milliseconds" << std::endl;

    delete[] ppl;

    return 0;
}