#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <algorithm>
#include <map>
#include <stack>
#include <unordered_map>
using namespace std;
    
#define ll long long
#define pl pair<ll,ll>
#define ppi pair<pl,int>
#pragma GCC optimize("O3")

const ll nmax = 2e+5 + 1;
int path_count[nmax];
vector<int> adj[nmax];

void solve(int a,int b,int n){
    // cout<<"solving..."<<endl;
    stack<int> s;
    s.push(a);
    int parent[n+1];
    unordered_map<int,int> visited;
    bool found = false;
    parent[a] = -1;
    while(!found && !s.empty()){
        // cout<<s.size()<<endl;
        int j = s.top();
        s.pop();
        visited[j] = 1;
        // cout<<adj[j].size()<<".."<<endl;
        for(auto c:adj[j]){
            // cout<<c<<endl;
            if(visited[c]) continue;
            parent[c] = j;
            // cout<<j<<" is parent of "<<c<<endl;
            // cout<<c<<" "<<b<<endl;
            if(c == b){
                found = true;
                break;
            }
            s.push(c);
        }
        // cout<<"found? "<<found<<endl;
    }
    // cout<<"found"<<endl;
    while(b != -1){
        path_count[b]++;
        b = parent[b];
    }
    // cout<<"updated path count.."<<endl;
}
    
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,m;
    cin >> n >> m;
    path_count[1] = 0;
    for (int i = 2; i <= n; i++)
    {
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
        path_count[i] = 0;
    }
    for (int i = 0; i < m; i++)
    {
        int a,b;
        cin >> a >> b;
        solve(a,b,n);
    }
    for (int i = 1; i <= n; i++)
    {
        cout<<path_count[i]<<" ";
    }
    cout<<endl;
}