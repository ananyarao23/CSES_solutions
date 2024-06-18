#include <bits/stdc++.h>
using namespace std;
    
#define ll long long
    
int main(){
    int n,m;
    cin >> n >> m;
    vector<vector<int>> edges(n+1);
    for (int i = 0; i < m; i++)
    {
        int a,b;
        cin >> a >> b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    int parent[n+1];
    bool visited[n+1];
    for (int i = 1; i <= n; i++)
    {
        parent[i] = -1;
        visited[i] = false;
    }
    queue<int> q;
    q.push(1);
    visited[1] = true;
    while(!q.empty()){
        int j = q.front();
        q.pop();
        for (int i = 0; i < edges[j].size(); i++)
        {
            if(!visited[edges[j][i]]){
                q.push(edges[j][i]);
                visited[edges[j][i]] = true;
                parent[edges[j][i]] = j;
            }
        }
    }
    if(parent[n] == -1) cout<<"IMPOSSIBLE"<<endl;
    else{
        vector<int> ans;
        
        int i = n;
        while(i != 1){
            ans.push_back(i);
            i = parent[i];
        }
        ans.push_back(1);
        cout<<ans.size()<<endl;
        for (int i = ans.size()-1; i >= 0; i--)
        {
            cout<<ans[i]<<" ";
        }
    }
}