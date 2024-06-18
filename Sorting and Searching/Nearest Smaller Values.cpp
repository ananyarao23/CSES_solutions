#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <algorithm>
#include <map>
#include <stack>
using namespace std;
    
#define ll long long
#define pl pair<ll,ll>
#define ppi pair<pl,int>
#pragma GCC optimize("O3","unroll-loops")
    
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n; cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    stack<pl> s;
    s.push({a[0],0});
    cout<<0<<" ";
    for (int i = 1; i < n; i++)
    {
        while(!s.empty() && s.top().first >= a[i]) s.pop();
        if(s.empty()) cout<<0<<" ";
        else cout<<s.top().second+1<<" ";
        s.push({a[i],i});
    }
    cout<<endl;
}