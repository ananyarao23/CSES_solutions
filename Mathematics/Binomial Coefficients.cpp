#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <algorithm>
#include <map>
using namespace std;
    
#define ll long long
#define pl pair<ll,ll>
#define ppi pair<pl,int>
#pragma GCC optimize("O3")
    
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n; cin >> n;
    ll a[n],b[n];
    ll max_a = -1,max_b = -1;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i] >> b[i];
        
        max_a = max(max_a,a[i]);
        max_b = max(max_b,b[i]);
    }
    // cout<<max_a<<" "<<max_b<<endl;
    ll prod_range[max_a+1][max_b+1];
    prod_range[1][1] = 1;
    for (int i = 2; i <= max_a; i++)
    {
        prod_range[i][1] = i*prod_range[i-1][1];
        for (int j = 2; j <= i; j++)
        {
            prod_range[i][j] = prod_range[i][j-1]/(j-1);
        }
    }
    for (int i = 0; i < n; i++)
    {
        ll x = a[i],y = b[i];
        cout<<x<<" "<<y<<endl;
        cout<<prod_range[x][y+1]/prod_range[x-y][1];
    }
}