#include <bits/stdc++.h>
using namespace std;
    
#define ll long long
const ll nmax = 100001;
const ll INF = 10000000000000000;
vector<ll> d;
#define p pair<int,int>
priority_queue<p,vector<p>,greater<p>> pq;
bool vis[nmax];
int parent[nmax];

void dijkstras(int src,vector<vector<int>> adj){
    d[src] = 0;
    pq.push({0,src});
    int cnt = 0;
    cout<<"-----------------"<<endl;
    while(cnt < adj.size()-1){
        auto pt = pq.top();
        cout<<pt.first<<" "<<pt.second<<endl;
        pq.pop();
        vis[pt.second] = true;
        cnt++;
        for (auto c:adj[pt.second])
        {
            cout<<d[pt.second]-1<<"---"<<d[c]<<endl;
            if(d[pt.second]-1 < d[c] && !vis[c]){
                d[c] = d[pt.second]-1;
                pq.push({d[pt.second]-1,c});
            }
        }
    }
}

    
int main(){
    int n,m;
    cin >> n >> m;
    vector<vector<int>> adj(n+1);
    for (int i = 0; i < m; i++)
    {
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
    }
    d.push_back(INF);
    for (int i = 1; i < n+1; i++)
    {
        d.push_back(INF);
        pq.push({INF,i});
        vis[i] = false;
        parent[i] = -1;
    }
    dijkstras(1,adj);
    cout<<-d[n]<<endl;
}