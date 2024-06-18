#include <bits/stdc++.h>
using namespace std;
    
#define ll long long
bool visited[100001];
    
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
    for (int i = 1; i < n+1; i++)
    {
        visited[i] = false;
    }
    stack<int> s;
    int connected_components=0;
    vector<int> roots;
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
    
}