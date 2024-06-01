#include <bits/stdc++.h>
using namespace std;
    
#define ll long long

struct Node{
    int val;
    Node* next;
};

Node* LinkedList(){
    Node* header = new Node;
    header->next = NULL;
    header->val = 0;
    return header;
}

Node* addAtEnd(Node* end, int val){
    Node* p = new Node;
    p->val = val;
    end->next = p;
    p->next = NULL;
    return p;
}

void addAtFront(Node* header,int val){
    Node* p = new Node;
    p->val = val;
    p->next = header->next;
    header->next = p;
}
    
int main(){
    int n; cin >> n;
    if(n==1){
        cout<<"1"<<endl;
    }
    else if(n < 4){
        cout<<"NO SOLUTION"<<endl;
    }
    else{
        Node* head = LinkedList(),*last;
        last = head;
        last = addAtEnd(last,2);
        last = addAtEnd(last,4);
        last = addAtEnd(last,1);
        last = addAtEnd(last,3);
        for (int i = 5; i <= n; i++)
        {
            if(i%2 == 0) last = addAtEnd(last,i);
            else addAtFront(head,i);
        }
        for (Node* i = head->next; i != NULL; i = i->next)
        {
            cout<<i->val<<" ";
        }
        cout<<endl;
    }
    // return 0;
}