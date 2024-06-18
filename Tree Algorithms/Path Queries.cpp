#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <algorithm>
#include <map>
#include <math.h>
using namespace std;
    
#define ll long long
#define pl pair<ll,ll>
#define ppi pair<pl,int>
#pragma GCC optimize("O3")

const int nmax = 2e+5 + 1;
vector<int> adj[nmax],path[nmax],x[nmax];


struct Node{
    int val;
};

void dfs(int r,int p){
    for(auto c:adj[r]){
        if(c == p) continue;
        path[c] = path[r];
        path[c].push_back(c);
        dfs(c,r);
    }
}
    
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,q;
    cin >> n >> q;
    Node* nodes = new Node[n+1];
    for (int i = 1; i <= n; i++)
    {
        int v; cin >> v;
        nodes[i].val = v;
    }
    
    for (int i = 0; i < n-1; i++)
    {
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    path[1].push_back(1);
    dfs(1,0);
    for (int i = 0; i < q; i++)
    {
        int type;
        cin >> type;
        if(type == 2){
            // cout<<"type 2"<<endl;
            int node; cin >> node;
            ll ans = 0;
            for(auto c:path[node]){
                ans += nodes[c].val;
            }
            cout<<ans<<endl;
        }
        else{
            // cout<<"type 1"<<endl;
            int node,val;
            cin >> node >> val;
            nodes[node].val = val;
        }
    }
    
}