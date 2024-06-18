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
const int nmax = 2e+5+1;
vector<int> adj[nmax];
int dist[nmax],dist2[nmax];

void dfs(int root,int parent){
    for(auto c:adj[root]){
        if(c == parent) continue;
        dist[c] = dist[root]+1;
        dfs(c,root);
    }
}

void dfs2(int root,int parent,int depth){
    for(auto c:adj[root]){
        if(c == parent) continue;
        dist[c] = max(dist[c],1+depth);
        dfs2(c,root,1+depth);
    }
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n; cin >> n;
    for (int i = 0; i < n-1; i++)
    {
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dist[1] = 0;
    dfs(1,0);
    int max_dist = -1,node1,node2;
    for (int i = 1; i <= n; i++)
    {
        if(max_dist < dist[i]){
            max_dist = dist[i];
            node1 = i;
        }
    }
    dist[node1] = 0;
    max_dist = -1;
    dfs(node1,0);
    for (int i = 1; i <= n; i++)
    {
        if(max_dist < dist[i]){
            max_dist = dist[i];
            node2 = i;
        }
    }
    dfs2(node2,0,0);
    for (int i = 1; i <= n; i++)
    {
        cout<<dist[i]<<" ";
    }
    cout<<endl;
}