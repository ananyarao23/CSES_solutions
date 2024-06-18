#include <bits/stdc++.h>
using namespace std;
    
#define ll long long

struct Node{
    int val;
    int parent;
    bool visited;
    vector<int> edges;
};

void initialise_nodes(int n,Node* nodes){
    for (int i = 1; i < n+1; i++)
    {
        nodes[i].val = i;
        nodes[i].parent = -1;
        nodes[i].visited = false;
    }
}

void form_edges(int m,Node* nodes){
    for (int i = 0; i < m; i++)
    {
        int a,b; cin >> a >> b;
        nodes[a].edges.push_back(b);
        nodes[b].edges.push_back(a);
    }
}

    
int main(){
    int n; cin >> n;
    int m; cin >> m;
    Node* nodes = new Node[n+1];
    initialise_nodes(n,nodes);
    form_edges(m,nodes);
    stack<int> s;
    bool cycle_detected = false;
    vector<int> ans;
    for (int i = 1; i <= n; i++)
    {
        if(nodes[i].visited) continue;
        s.push(i);
        while (!s.empty())
        {
            int j = s.top();
            s.pop();
            nodes[j].visited = true;
            for (int i = 0; i < nodes[j].edges.size(); i++)
            {
                if(nodes[nodes[j].edges[i]].visited){
                    if(nodes[j].edges[i] != nodes[j].parent){
                        int k = j;
                        ans.push_back(nodes[j].edges[i]);
                        while(k != nodes[j].edges[i]){
                            ans.push_back(k);
                            k = nodes[k].parent;
                        }
                        ans.push_back(nodes[j].edges[i]);
                        cycle_detected = true;
                        break;
                    }
                    else continue;
                }
                nodes[nodes[j].edges[i]].parent = j;
                s.push(nodes[j].edges[i]);
            }
            if(cycle_detected) break;
        }
        if(cycle_detected) break;
    }
    if(!cycle_detected){
        cout<<"IMPOSSIBLE"<<endl;
    }
    else{
        cout<<ans.size()<<endl;
        for(auto c:ans) cout<<c<<" ";
    }
}