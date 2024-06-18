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
vector<int> adj[nmax],nodes_in_subtree_at(nmax),parent(nmax);

int dfs(int r,int p){
    nodes_in_subtree_at[r] = 1;
    for(auto c:adj[r]){
        if(c == p) continue;
        parent[c] = r;
        nodes_in_subtree_at[r] += dfs(c,r);
    }
    return nodes_in_subtree_at[r];
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
    nodes_in_subtree_at[1] = dfs(1,0);
    parent[1] = -1;
    for (int i = 1; i <= n; i++)
    {
        bool valid = true;
        for (auto c:adj[i])
        {
            if(c != parent[i]){
                if(nodes_in_subtree_at[c] > n/2){
                    valid = false;
                    break;
                }
            }
            else{
                if(nodes_in_subtree_at[1] - nodes_in_subtree_at[i] > n/2){
                    valid = false;
                    break;
                }
            }
        }
        if(valid){
            cout<<i<<endl;
            break;
        }
    }
    
}