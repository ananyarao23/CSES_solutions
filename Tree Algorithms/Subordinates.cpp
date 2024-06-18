#include <bits/stdc++.h>
using namespace std;
    
#define ll long long
const ll nmax = 200001;

struct node{
    int nodes_in_subtree;
    vector<int> children;
};

int count_nodes(int src,node* nodes){
    int cnt = 0;
    if(nodes[src].children.size() == 0){
        nodes[src].nodes_in_subtree = 0;
        return 0;
    }
    for (auto c:nodes[src].children)
    {
        cnt += (1+count_nodes(c,nodes));
    }
    nodes[src].nodes_in_subtree = cnt;
    return cnt;
}
    
int main(){
    int n; cin >> n;
    node* nodes = new node[n+1];
    for (int i = 1; i < n+1; i++)
    {
        nodes[i].nodes_in_subtree = 0;
    }
    for (int i = 2; i < n+1; i++)
    {
        int a; cin >> a;
        nodes[a].children.push_back(i);
    }
    count_nodes(1,nodes);
    for (int i = 1; i < n+1; i++)
    {
        cout<<nodes[i].nodes_in_subtree<<" ";
    }
    cout<<endl;
}