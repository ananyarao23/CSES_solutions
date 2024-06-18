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
#define pb push_back
#pragma GCC optimize("O3")
const int nmax = 2e+5 + 1;
vector<int> adj[nmax];
int depth[nmax],jump[19][nmax];

void dfs(int root,int p){
    for(auto c:adj[root]){
        if(c == p) continue;
        jump[0][c] = root;
        depth[c] = depth[root]+1;
        dfs(c,root);
    }
}

void populate_jumps(int n){
    for (int i = 1; i < 19; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            jump[i][j] = jump[i-1][jump[i-1][j]];
        }
    }
}

int find_lca(int n1,int n2){
    int diff = depth[n1]-depth[n2];
    if(diff > 0){
        for (int i = 0; i < 19; i++)
        {
            if((diff >> i)&1) n1 = jump[i][n1];
        }
    }
    else{
        for (int i = 0; i < 19; i++)
        {
            if((-diff >> i)&1) n2 = jump[i][n2];
        }
    }
    if(n1 == n2) return n1;
    for (int i = 18; i > -1; i--)
    {
        if(jump[i][n1] != jump[i][n2]){
            n1 = jump[i][n1];
            n2 = jump[i][n2];
        }
    }
    return jump[0][n1];
}
    
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,q;
    cin >> n >> q;
    for (int i = 0; i < n-1; i++)
    {
        int a,b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    depth[1] = 0;
    dfs(1,0);
    jump[0][0] = 0;
    jump[0][1] = 0;
    populate_jumps(n);
    for (int i = 0; i < q; i++)
    {
        int a,b;
        cin >> a >> b;
        int lca = find_lca(a,b);
        cout<<depth[a]+depth[b]-2*depth[lca]<<endl;
    }
}