#include <bits/stdc++.h>
using namespace std;
    
#define ll long long

struct Node
{
    int team;
    int val;
    bool visited;
    vector<int> edges;
};
bool assign_teams(int root,Node* nodes){
    int cur_team = nodes[root].team;
    for (int i = 0; i < nodes[root].edges.size(); i++)
    {
        if(nodes[nodes[root].edges[i]].team == cur_team) return false;
        if(nodes[nodes[root].edges[i]].visited) continue;
        if(cur_team == 1) nodes[nodes[root].edges[i]].team = 2;
        else nodes[nodes[root].edges[i]].team = 1;
        nodes[nodes[root].edges[i]].visited = true;
        if(!assign_teams(nodes[root].edges[i],nodes)) return false;
    }
    return true;
}

    
int main(){
    int n,m;
    cin >> n >> m;
    Node* nodes = new Node[n+1];
    for(int i=1;i<=n;i++){
        nodes[i].val = i;
        nodes[i].team = 0;
        nodes[i].visited = false;
    }
    for (int i = 0; i < m; i++)
    {
        int a,b; cin >> a >> b;
        nodes[a].edges.push_back(b);
        nodes[b].edges.push_back(a);
    }
    bool impossible = false;
    for (int i = 1; i < n+1; i++)
    {
        if(nodes[i].visited) continue;
        nodes[i].team = 1;
        nodes[i].visited = true;
        if(!assign_teams(i,nodes)){
            cout<<"IMPOSSIBLE"<<endl;
            impossible = true;
            break;
        }
    }
    if(!impossible){
        for (int i = 1; i <= n; i++)
        {
            cout<<nodes[i].team<<" ";
        }
        cout<<endl;
    }
}