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
int dist[nmax] = {0};
vector<int> adj[nmax];

void dfs(int root, int parent){
    for(auto c:adj[root]){
        if(c == parent) continue;
        dist[c] = dist[root]+1;
        dfs(c,root);
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
    int max_dist = -1,node;
    for(int i = 1;i <= n;i++){
        if(dist[i] > max_dist){
            max_dist = dist[i];
            node = i;
        }
    }
    dist[node] = 0;
    dfs(node,0);
    max_dist = -1;
    for(int i = 1;i <= n;i++){
        if(dist[i] > max_dist){
            max_dist = dist[i];
        }
    }
    cout<<max_dist<<endl;
}