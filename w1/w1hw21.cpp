// https://neoj.sprout.tw/problem/21/
#include <bits/stdc++.h>
#define boost ios::sync_with_stdio(0);cin.tie(0)
#define endl '\n'
#define ll long long
#define pii pair<int, int>
#define mpii(a, b) make_pair(a, b) 

using namespace std; 

class Node {
    public:
        int data;
    Node* next;
    Node* head;
};

void print_list_head(Node* n) {
    while (n != NULL) {
        cout << n->data << " ";
        n = n -> next;
    }
}

void print_list_tail(Node* n) {
    while (n != NULL) {
        cout << n->data << " ";
        n = n -> head;
    }
}

vector<Node*> line(100002);

int main() {
    // boost;
    
    int n, m, t, x;
    cin >> n >> m;
    Node* node = NULL;
    Node* temp = NULL;
    Node* temp2 = NULL;
    for(int i = 0; i <= n + 1; i++) {
        node = new Node();
        node -> data = i;
        node -> head = temp;
        if(i != 0) {
            temp -> next = node;
            line[i - 1] = temp;
        }
        temp = node;
    }
    temp -> next = NULL;
    line[n + 1] = temp;
    line[n + 2] = NULL;
    // print_list_head(line[0]);
    // cout << endl;
    // print_list_tail(line[n+1]);
    // cout << endl;
    while(m--) {
        cin >> t >> x;
        if(t ==0) {
            line[x] -> head -> next = line[x] -> next;
            line[x] -> next -> head = line[x] -> head;
            // delete line[x];
            n--;
        }else if(line[x] != line[0] -> next){
            line[x] -> head -> head -> next = line[x];
            line[x] -> head -> next = line[x] -> next;
            temp2 = line[x] -> next;
            line[x] -> next = line[x] -> head;
            temp = line[x] -> head -> head;
            line[x] -> head -> head = line[x];
            temp2 -> head = line[x] -> head;
            line[x] -> head = temp;
        }
        // print_list_head(line[0]);
        // cout << endl;
        // print_list_tail(line[8]);
        // cout << endl;
    }
    node = line[0];
    while(node != NULL) {
        if(n == 1) {
            cout << node -> data << endl;
            n--;
        }else if(node -> data != 0 && n > 0) {
            cout << node -> data << " ";
            n--;
        }
        node = node -> next;
    }
    
    return 0;
}