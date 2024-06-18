#include <bits/stdc++.h>
using namespace std;
    
#define ll long long
bool visited[100001];

// void dfs(int root,vector<vector<int>> edges){
//     visited[root] = true;
//     for(int i=0;i<edges[root].size();i++){
//         if(visited[edges[root][i]]) continue;;
//         dfs(edges[root][i],edges);
//     }
// }

    
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
    int connected_components=0;
    for (int i = 0; i <= n; i++)
    {
        visited[i] = false;
    }
    vector<int> roots;
    stack<int> s;
    for (int i = 1; i <= n; i++)
    {
        if(visited[i]) continue;
        connected_components++;
        roots.push_back(i);
        s.push(i);
        while(!s.empty()){
            int j = s.top();
            s.pop();
            visited[j] = true;
            for (int k = 0; k < edges[j].size(); k++)
            {
                if(!visited[edges[j][k]]){
                    s.push(edges[j][k]);
                }
            }
        }
    }
    cout<<connected_components-1<<endl;
    for (int i = 0; i < roots.size()-1; i++)
    {
        cout<<roots[i]<<" "<<roots[i+1]<<endl;
    }
}