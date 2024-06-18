#include <bits/stdc++.h>
using namespace std;
    
#define ll long long
const int nmax = 100001;
bool vis[nmax];
int v[nmax];
stack<int> ans;

bool topo(int src,vector<vector<int>> nodes){
    stack<int> s;
    s.push(src);
    bool rem = true;
    while(rem){
        rem = false;
        src = s.top();
        vis[src] = true;
        v[src] = 1;
        for(auto c:nodes[src]){
            if(vis[c]){
                if(v[c] == 1){
                    cout<<"IMPOSSIBLE"<<endl;
                    return false;
                }
                continue;
            }
            rem = true;
            s.push(c);
        }
    }
    while(!s.empty()){
        v[s.top()] = 2;
        ans.push(s.top());
        s.pop();
    }
    return true;
}

    
int main(){
    int n,m;
    cin >> n >> m;
    vector<vector<int>> nodes(n+1);
    for (int i = 1; i <= n; i++)
    {
        vis[i] = false;
        v[i] = 0;
    }
    for (int i = 0; i < m; i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        nodes[a].push_back(b);
    }
    bool noSolution = false;
    for (int i = 1; i < n+1; i++)
    {
        if(vis[i]) continue;
        if(!topo(i,nodes)){
            noSolution = true;
            break;
        }
    }
    if(!noSolution){
        while(!ans.empty()){
            cout<<ans.top()<<" ";
            ans.pop();
        }
        cout<<endl;
    }
}