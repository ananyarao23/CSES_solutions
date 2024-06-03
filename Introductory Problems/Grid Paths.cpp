#include <bits/stdc++.h>
using namespace std;
    
#define ll long long
int c[48];
int ans = 0;

int move_x(int n,int x){
    if(n == 0 && x > 0) return x-1;
    if(n == 1) return x;
    if(n == 2 && x < 48) return x+1;
    if(n == 3) return x;
    return -1;
}

int move_y(int n,int x){
    if(n == 0) return x;
    if(n == 1 && x < 48) return x+1;
    if(n == 2) return x;
    if(n == 3 && x > 0) return x-1;
    return -1;
}

void solve(int n,int x,int y){
    // cout<<"Solving"<<endl;
    // cout<<"At ("<<x+1<<","<<y+1<<") with n="<<n<<endl; 
    if(n == 49){
        // cout<<"Reached"<<endl;
        if(x == 48 && y == 48) ans++;
    }
    if(x == -1 || y == -1) return;
    // cout<<c[n]<<" "<<n<<endl;
    if(c[n] == -1){
        for (int i = 0; i < 4; i++)
        {
            // cout<<"Going "<<i<<endl;
            solve(n+1,move_x(i,x),move_y(i,y));
        }
        
    }
    else solve(n+1,move_x(c[n],x),move_y(c[n],y));
}
    
int main(){
    string s; cin >> s;
    for (int i = 0; i < s.length(); i++)
    {
        if(s[i] = '?') c[i] = -1;
        else if(s[i] = 'U') c[i] = 0;
        else if(s[i] = 'R') c[i] = 1;
        else if(s[i] = 'D') c[i] = 2;
        else if(s[i] = 'L') c[i] = 3;
    }
    solve(0,0,0);
    cout<<ans<<endl;
}