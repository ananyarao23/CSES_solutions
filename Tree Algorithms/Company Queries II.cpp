#include <bits/stdc++.h>
using namespace std;
    
#define ll long long
#define pl pair<ll,ll>
#define ppi pair<pl,int>
#pragma GCC optimize("O3")
 
struct node{
    int val;
    bool visited;
    int depth;
    vector<int> family;
};
    
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,q; cin >> n >> q;
    int LOG = 19;
    int** jump = new int*[LOG];
    for (int i = 0; i < LOG; i++)
    {
        jump[i] = new int[n+1];
    }
    vector<int> adj[n+1];
    jump[0][1] = 0;
    jump[0][0] = 0;
    for (int i = 2; i <= n; i++)
    {
        int a; cin >> a;
        jump[0][i] = a;
        adj[jump[0][i]].push_back(i);
    }
    // cout<<"yha??"<<endl;
    for (int i = 1; i < LOG; i++)
    {
        // cout<<i<<"th........."<<endl;
        for (int j = 0; j < n+1; j++)
        {
            jump[i][j] = jump[i-1][jump[i-1][j]];
            // cout<<"jump["<<i-1<<"][jump["<<i-1<<"]["<<j<<"]]: jump["<<i-1<<"]["<<jump[i-1][j]<<"]: "<<jump[i][j]<<endl;
        }
    }
    // cout<<"yha tak"<<endl;
    node* Nodes = new node[n+1];
    stack<int> s;
    s.push(1);
    Nodes[1].depth = 0;
    while(!s.empty()){
        int p = s.top();
        s.pop();
        Nodes[p].visited = true;
        for(auto c:adj[p]){
            if(Nodes[c].visited) continue;
            Nodes[c].depth = Nodes[p].depth+1;
            s.push(c);
        }
    }
    for (int i = 0; i < q; i++)
    {
        int n1,n2;
        cin >> n1 >> n2;
        // cout<<Nodes[n1].depth<<" "<<Nodes[n2].depth<<endl;
        int diff = Nodes[n2].depth - Nodes[n1].depth;
        if(diff > 0){
            for (int j = 0; j < 19; j++)
            {
                if((diff >> j) & 1) n2 = jump[j][n2];
            }
        }
        else{
            for (int j = 0; j < 19; j++)
            {
                if((-diff >> j) & 1) n1 = jump[j][n1];
            }
        }
        if(n1 == n2) cout<<n1<<endl;
        else{
            for (int j = LOG-1; j > -1; j--)
            {
                if(jump[j][n1] != jump[j][n2]){
                    n1 = jump[j][n1];
                    n2 = jump[j][n2];
                    // cout<<j<<" "<<n1<<" "<<n2<<endl;
                }
            }
            cout<<jump[0][n1]<<endl;
        }
    }
    
}