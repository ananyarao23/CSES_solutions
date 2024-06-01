#include <bits/stdc++.h>
using namespace std;

int n,m;
int edges[1000][1000];
int path_length = 1000000;
string path = "";
bool visited[1000][1000];
int l[4] = {0,0,1,-1};
int r[4] = {1,-1,0,0};

void dfs_find_path(string s,int count,int i,int j){
    count++;
    bool reached = false;
    for (int x = 0; x < 4; x++)
    {
        if((i+l[x]) >= 0 && (i+l[x]) < n && (j+r[x]) >= 0 && (j+r[x]) < m && !visited[i+l[x]][j+r[x]]){
            string str = s;
            int temp_count = count;
            if(r[x] == 1) str.push_back('R');
            if(r[x] == -1) str.push_back('L');
            if(l[x] == 1) str.push_back('D');
            if(l[x] == -1) str.push_back('U');

            if(edges[i+l[x]][j+r[x]] == -2){
                reached = true;
                count++;
                s = str;
                break;
            }

            if(edges[i+l[x]][j+r[x]] == 0){
                visited[i+l[x]][j+r[x]] = true;
                dfs_find_path(str,temp_count,i+l[x],j+r[x]);    
            }
        }
    }
    if(reached){
        if(count < path_length){
            path = s;
            path_length = count;
        }
        return;
    }
    // bool path_left = false;

}

void dfs(int i,int j){
    bool reached = false;
    string s = "";
    int count = 0;
    for (int x = 0; x < 4; x++)
    {
        if((i+l[x]) >= 0 && (i+l[x]) < n && (j+r[x]) >= 0 && (j+r[x]) < m && edges[i+l[x]][j+r[x]] == -2){
            if(r[x] == 1) s.push_back('R');
            if(r[x] == -1) s.push_back('L');
            if(l[x] == 1) s.push_back('D');
            if(l[x] == -1) s.push_back('U');
            reached = true;
            count++;
            break;
        }
    }
    if(reached){
        if(count < path_length){
            path = s;
            path_length = count;
        }
        return;
    }
    for (int x = 0; x < 4; x++)
    {
        if((i+l[x]) >= 0 && (i+l[x]) < n && (j+r[x]) >= 0 && (j+r[x]) < m && !visited[i+l[x]][j+r[x]] && edges[i+l[x]][j+r[x]] == 0){
            string str = "";
            int temp_count = 0;
            if(r[x] == 1) str.push_back('R');
            if(r[x] == -1) str.push_back('L');
            if(l[x] == 1) str.push_back('D');
            if(l[x] == -1) str.push_back('U');
            visited[i+l[x]][j+r[x]] = true;
            dfs_find_path(str,temp_count,i+l[x],j+r[x]);
        }
    }
}
    
int main(){
 // n - rows, m - columns
    cin >> n >> m;
    int s_x,s_y,e_x,e_y;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            char s; cin >> s;
            visited[i][j] = false;
            if (s=='A'){
                s_x = i;s_y = j;
                edges[i][j] = 2;
            }
            else if (s=='B'){
                e_x = i;e_y = j;
                edges[i][j] = -2;
            }
            else if (s=='#') edges[i][j] = 1;
            else edges[i][j] = 0;
        }
    }
    dfs(s_x,s_y);
    if(path == "") cout<<"NO";
    else{
        cout<<"YES"<<endl;
        cout<<path_length<<endl;
        cout<<path<<endl;
    }
}