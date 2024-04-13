#include <bits/stdc++.h>
#define boost ios::sync_with_stdio(0);cin.tie(0)
#define endl '\n'
#define ll long long
#define pii pair<int, int>
#define mpii(a, b) make_pair(a, b) 

using namespace std; 

const int MAXN = 100;
struct Queue { // circular queue, avoid fronter space unused 
    int arr[MAXN], head, tail;
    /* if you want MAXN to be a floating integer, the use vector
    vector<int> arr;
    Queue(int n) : head(0), tail(0) {
        arr.resize(n);
    }
    */
    int front() {
        return arr[head];
    }
    void pop() {
        head = (head + 1) % MAXN;
    }
    void push(int val) {
        arr[tail] = val;
        tail = (tail + 1) % MAXN;
    }
    int size() {
        return (tail - head + MAXN) % MAXN;
    }
};
Queue qu; //front() pop() push() size()

struct Stack { // open as big as the problem required 
    int arr[MAXN], top;
    Stack(): top(0) {}
    int top() {
        return arr[top-1];
    }
    void pop() {
        top--;
    }
    void push(int val) {
        arr[top++] = val;
    }
    int size() {
        return top;
    }
};
Stack stk; // top() pop() push() size()

//deque => queue + stack

int main() {
    boost;
    
    
    
    return 0;
}