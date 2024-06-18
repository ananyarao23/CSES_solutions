#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nmax 2501
const ll INF = 100000000000000;
bool vis[nmax], visR[nmax];
vector<vector<int>> adj(nmax);
vector<vector<int>> adjR(nmax);

struct edge
{
    int from, to;
    ll cost;
};

void dfs(int idx)
{
    stack<int> s;
    s.push(idx);
    while (!s.empty())
    {
        idx = s.top();
        s.pop();
        vis[idx] = true;
        for (auto c : adj[idx])
        {
            if (vis[c])
                continue;
            s.push(c);
        }
    }
}

void dfsR(int idx)
{
    stack<int> s;
    s.push(idx);
    while (!s.empty())
    {
        idx = s.top();
        s.pop();
        visR[idx] = true;
        for (auto c : adjR[idx])
        {
            if (visR[c])
                continue;
            s.push(c);
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    edge *edges = new edge[m];
    vector<ll> d(n + 1, INF);
    for (int i = 1; i <= n; i++)
    {
        vis[i] = false;
        visR[i] = false;
    }
    for (int i = 0; i < m; i++)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        edges[i].cost = -c;
        edges[i].from = a;
        edges[i].to = b;
        adj[a].push_back(b);
        adjR[b].push_back(a);
    }
    dfs(1);
    dfsR(n);

    bool rise = true;
    d[1] = 0;
    bool no_sol = false;
    for (int i = 0; i < n && rise; i++)
    {
        rise = false;
        for (int j = 0; j < m; j++)
        {
            if ((d[edges[j].from] + edges[j].cost) < d[edges[j].to])
            {
                rise = true;
                d[edges[j].to] = d[edges[j].from] + edges[j].cost;
            }
        }
    }
    for (int j = 0; j < m; j++)
    {
        if (((d[edges[j].from] + edges[j].cost) < d[edges[j].to]) && vis[edges[j].to] && visR[edges[j].to])
        {
            no_sol = true;
            break;
        }
    }
    if(no_sol) cout<<"-1"<<endl;
    else cout<<-d[n]<<endl;
}