#include <bits/stdc++.h>
using namespace std;
    
#define ll long long
#define INTMAX 1000000
vector<pair<int,int>> monsters;
pair<int,int> me;

struct Node{
    bool A;
    bool M;
    char val;
    bool end;
    bool visited;
    int depth;
    pair<int,int> parent;
    vector<pair<int,int>> v;
};

bool bfs(pair<int,int> end,int n,int m,Node** nodes){
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            nodes[i][j].visited = false;
            nodes[i][j].depth = INTMAX;
        } 
    }
    nodes[end.first][end.second].depth = 0;
    queue<pair<int,int>> q;
    q.push({end.first,end.second});
    nodes[end.first][end.second].visited = true;
    while(!q.empty()){
        auto pt = q.front();
        q.pop();
        for (auto c:nodes[pt.first][pt.second].v)
        {
            if(nodes[c.first][c.second].visited) continue;
            nodes[c.first][c.second].parent = pt;
            nodes[c.first][c.second].depth = nodes[pt.first][pt.second].depth+1;
            nodes[c.first][c.second].visited = true;
            q.push(c);
        }
    }
    int my_depth = nodes[me.first][me.second].depth;
    if(my_depth == INTMAX){
        return false;
    }
    for (auto c:monsters)
    {
        if(nodes[c.first][c.second].depth <= my_depth) return false;
    }
    cout<<"YES"<<endl;
    cout<<my_depth<<endl;
    auto c = me;
    // cout<<end.first<<" "<<end.second<<endl;
    // cout<<"================"<<endl;
    while(c.first != end.first || c.second != end.second){
        // cout<<endl<<c.first<<" "<<c.second<<endl;
        auto pt = nodes[c.first][c.second].parent;
        int diff1 = pt.first - c.first;
        int diff2 = pt.second - c.second;
        if(diff1 == -1 && diff2 == 0) cout<<"U";
        if(diff1 == 1 && diff2 == 0) cout<<"D";
        if(diff1 == 0 && diff2 == 1) cout<<"R";
        if(diff1 == 0 && diff2 == -1) cout<<"L";
        c = pt;
    }
    cout<<endl;
    return true;
}

void solve(vector<pair<int,int>> end_points,int n,int m,Node** nodes){
    for (int i = 0; i < end_points.size(); i++)
    {
        if(bfs(end_points[i],n,m,nodes)){
            return;
        }
    }
    cout<<"NO"<<endl;
    return;
}
    
int main(){
    int n,m;
    cin >> n >> m;
    int num_nodes = 0;
    Node** nodes = new Node*[n];
    for (int i = 0; i < n; i++)
    {
        nodes[i] = new Node[m];
    }
    vector<pair<int,int>> end_points;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> nodes[i][j].val;
            if(nodes[i][j].val == '#') continue;
            if(i-1 >= 0 && nodes[i-1][j].val != '#'){
                nodes[i-1][j].v.push_back({i,j});
                nodes[i][j].v.push_back({i-1,j});
            }
            if(j-1 >= 0 && nodes[i][j-1].val != '#'){
                nodes[i][j-1].v.push_back({i,j});
                nodes[i][j].v.push_back({i,j-1});
            }
            if(nodes[i][j].val == 'A'){
                nodes[i][j].A = true;
                me = {i,j};
            }
            else nodes[i][j].A = false;
            if(nodes[i][j].val == 'M'){
                nodes[i][j].M = true;
                monsters.push_back({i,j});
            }
            else nodes[i][j].M = false;
            if(i == n-1 || j == m-1){
                nodes[i][j].end = true;
                end_points.push_back({i,j});
            }
            else nodes[i][j].end = false;

        }
    }
    solve(end_points,n,m,nodes);
}