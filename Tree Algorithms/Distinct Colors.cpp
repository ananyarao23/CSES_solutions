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
 
const int nmax = 2e+5 +1;
vector<int> adj[nmax];
 
struct Node{
    int color;
    set<int> colors_in_subtree;
    vector<int> children;
};
 
Node* nodes = new Node[nmax];
 
set<int> dfs(int r, int p){
    for(auto c:adj[r]){
        if(c == p) continue;
        nodes[r].children.push_back(c);
        set<int> color_in_child = dfs(c,r);
        for(auto it = color_in_child.begin();it != color_in_child.end();it++){
            if(nodes[r].colors_in_subtree.find(*it) == nodes[r].colors_in_subtree.end()){
                nodes[r].colors_in_subtree.insert(*it);
            }
        }
    }
    return nodes[r].colors_in_subtree;
}
    
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n; cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int c; cin >> c;
        nodes[i].color = c;
        nodes[i].colors_in_subtree.insert(c);
    }
    
    for (int i = 0; i < n-1; i++)
    {
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1,0);
    for (int i = 1; i <= n; i++)
    {
        cout<<nodes[i].colors_in_subtree.size()<<" ";
    }
    cout<<endl;
}