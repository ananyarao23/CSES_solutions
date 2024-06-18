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

bool valid(ll a[],ll sum,int k,int n){
    ll curr_sum = 0;
    ll partitions = 0;
    for (int i = 0; i < n; i++)
    {
        if(curr_sum+a[i] > sum){
            partitions++;
            curr_sum = a[i];
        }
        else curr_sum += a[i];
        if(i == n-1) partitions++;
    }
    return partitions <= k;
}

void solve(ll a[],ll bs[],int k,int sz,ll n){
    ll l = 0,r = n-1,mid;
    ll ans;
    while(l <= r){
        mid = (l+r)/2;
        if(valid(a,bs[mid],k,sz)){
            r = mid-1;
            ans = bs[mid];
        }
        else{
            l = mid+1;
        }
    }
    cout<<ans<<endl;
}
    
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,k; cin >> n >> k;
    ll a[n];
    ll max_e = -1;
    ll sum = 0;
    for (int i = 0; i < n; i++){
        cin >> a[i];
        if(a[i] > max_e) max_e = a[i];
        sum += a[i];
    }
    ll bs[sum-max_e+1];
    for (int i = 0; i < sum-max_e+1; i++)
    {
        bs[i] = max_e+i;
    }
    solve(a,bs,k,n,sum-max_e+1);
}