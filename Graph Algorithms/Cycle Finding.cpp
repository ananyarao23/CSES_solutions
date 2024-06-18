#include <bits/stdc++.h>
using namespace std;
    
#define ll long long
const ll INF = 10000000000000000;

struct Edge
{
    int from,to;
    ll cost;
};

    
int main(){
    int n,m;
    cin >> n >> m;
    Edge* edges = new Edge[m];
    for (int i = 0; i < m; i++)
    {
        int a,b; ll c;
        scanf("%d%d%lld",&a,&b,&c);
        edges[i].from = a;
        edges[i].to = b;
        edges[i].cost = c;
    }
    vector<ll> d(n+1,INF);
    d[1] = 0;
    bool improve = true;
    bool sol = false;
    int idx;
    for (int i = 0; i < n && improve; i++)
    {
        improve = false;
        for (int j = 0; j < m; j++)
        {
            if(d[edges[j].from] + edges[j].cost < d[edges[j].to]){
                improve = true;
                d[edges[j].to] = d[edges[j].from] + edges[j].cost;
            }
        }
        if(i == n-1){
            for (int j = 0; j < m; j++)
            {
                if(d[edges[j].from] + edges[j].cost < d[edges[j].to]){
                    d[edges[j].to] = d[edges[j].from] + edges[j].cost;
                    sol = true;
                    idx = edges[j].to;
                }
            }
        }
    }
    
}