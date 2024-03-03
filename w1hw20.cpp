// https://neoj.sprout.tw/problem/20/
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
};

void print_list(Node* n) {
    while (n != NULL) {
        cout << n->data << " ";
        n = n -> next;
    }
}
vector<Node*> group_tail(1000, NULL);
int* ppl = new int[1000000];

int main() {
    boost;
    
    int t, n, k, id, m;
    string cmd;
    bool flag = false;
    Node* head = NULL;
    Node* tail = NULL;
    fill(ppl, ppl + 1000000, -1);
    cin >> t;
    for(int i = 0; i < t; i++) {
        group_tail.assign(1000, NULL);
        cout << "Line #" << i + 1 << endl;
        cin >> n;
        flag = false;
        for(int j = 0; j < n; j++) {
            cin >> k;
            while(k--) {
                cin >> id;
                ppl[id] = j;
            }
        }
        cin >> m;
        while(m--) {
            cin >> cmd;
            if(cmd == "ENQUEUE") {
                cin >> id;
                Node* node = new Node();
                node -> data = id;
                if(!flag) {
                    node -> next = NULL;
                    head = node;
                    tail = node;
                    flag = true;
                }else if(ppl[id] == -1 || group_tail[ppl[id]] == NULL) {
                    node -> next = NULL;
                    tail -> next = node;
                    tail = node;
                }else{
                    node -> next = group_tail[ppl[id]] -> next;
                    group_tail[ppl[id]] -> next = node;
                    if(group_tail[ppl[id]] == tail) tail = node;
                }
                if(ppl[id] != -1) group_tail[ppl[id]] = node;
            }else{
                cout << head -> data << endl;
                if(head -> next != NULL && ppl[head -> data] != ppl[head -> next -> data]) group_tail[ppl[head -> data]] = NULL;
                if(head -> next != NULL) head = head -> next;
            }
            // print_list(head);
            // cout << tail -> data << endl;
        }
    }    
    delete[] ppl;
    return 0;
}