#include <bits/stdc++.h>
using namespace std;

#define ll long long
const ll INF = 1000000000000000;
#define nmax 100001
typedef pair<ll, int> dist;
vector<ll> d(nmax + 1, INF), dR(nmax + 1, INF);

struct edge
{
    int to;
    ll cost;
};

vector<vector<edge>> adj(nmax + 1);
vector<vector<edge>> adjR(nmax + 1);

class Graph
{
public:
    int nodes;
    bool sp[nmax];
    priority_queue<dist, vector<dist>, greater<dist>> pq;
    Graph(int n)
    {
        nodes = n;
        for (int i = 1; i <= n; i++)
        {
            sp[i] = false;
        }
    }

    void add_edges()
    {
        for (int i = 1; i <= nodes; i++)
        {
            pq.push({INF, i});
        }
    }
};

void dijkstra(int root, int n)
{
    Graph G(n);
    G.add_edges();
    G.pq.push({0, root});
    d[root] = 0;
    int cnt = 0;
    while (cnt < n)
    {
        auto pt = G.pq.top();
        G.pq.pop();
        G.sp[pt.second] = true;
        cnt++;
        for (auto c : adj[pt.second])
        {
            if (d[pt.second] + c.cost < d[c.to])
            {
                d[c.to] = c.cost + d[pt.second];
                G.pq.push({d[c.to], c.to});
            }
        }
    }
}

void dijkstraR(int root, int n)
{
    Graph G(n);
    G.add_edges();
    G.pq.push({0, root});
    int cnt = 0;
    dR[root] = 0;
    while (cnt < n)
    {
        auto pt = G.pq.top();
        G.pq.pop();
        G.sp[pt.second] = true;
        cnt++;
        for (auto c : adjR[pt.second])
        {
            if (dR[pt.second] + c.cost < dR[c.to])
            {
                dR[c.to] = c.cost + dR[pt.second];
                G.pq.push({dR[c.to], c.to});
            }
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        ll c;
        scanf("%d%d%lld", &a, &b, &c);
        adj[a].push_back({b, c});
        adjR[b].push_back({a, c});
    }
    dijkstra(1, n);
    dijkstraR(n, n);
    ll min_dist = INF;
    for (int i = 1; i <= n; i++)
    {
        ll d1 = d[i], d2;
        for (auto c : adj[i])
        {
            d2 = dR[c.to];
            if ((d1 + d2 + c.cost / 2) < min_dist)
                min_dist = (d1 + d2 + c.cost / 2);
        }
    }
    cout << min_dist << endl;
}