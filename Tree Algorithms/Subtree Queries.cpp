#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <algorithm>
#include <map>
using namespace std;
    
#define ll long long
#define pl pair<ll,ll>
#define ppi pair<pl,int>
#pragma GCC optimize("O3")

const int nmax = 2e+5 + 1;
ll node_val[nmax],node_sum[nmax],parent[nmax];
vector<int> adj[nmax];

ll dfs(int r,int p){
    node_sum[r] = node_val[r];
    for(auto c:adj[r]){
        if(c == p) continue;
        parent[c] = r;
        node_sum[r] += dfs(c,r);
    }
    return node_sum[r];
}
    
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        int a; cin >> a;
        node_val[i] = a;
    }
    for (int i = 0; i < n-1; i++)
    {
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1,0);
    parent[1] = 0;
    for (int i = 0; i < q; i++)
    {
        int t; cin >> t;
        if(t == 1){
            ll node,val;
            cin >> node >> val;
            int p = node;
            while(p != 0 && node_val[node] != val){
                // cout<<"Updated tree rooted at "<<p<<" from "<<node_sum[p]<<" to ";
                node_sum[p] += (val-node_val[node]);
                p = parent[p];
            }
            node_val[node] = val;
        }
        else{
            int node; cin >> node;
            cout<<node_sum[node]<<endl;
        }
    }
    
}