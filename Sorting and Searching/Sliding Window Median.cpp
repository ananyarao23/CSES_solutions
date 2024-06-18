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

multiset<ll> low,high;

void insert(int idx,ll a[],int k){
    if(low.empty()){
        high.insert(a[idx]);
        low.insert(*high.begin());
        high.erase(high.begin());
        return;
    }
    if(a[idx] > *low.rbegin()){
        high.insert(a[idx]);
        if(high.size() > k/2){
            low.insert(*high.begin());
            high.erase(high.begin());
        }
    }
    else{
        low.insert(a[idx]);
        if(low.size() > (k+1)/2){
            high.insert(*low.rbegin());
            low.erase(low.find(*low.rbegin()));
        }
    }
}

void erase(int idx,ll a[]){
    if(a[idx] > *low.rbegin()){
        high.erase(high.find(a[idx]));
    }
    else{
        low.erase(low.find(a[idx]));
    }
}
    
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,k; cin >> n >> k;
    ll arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];
    for (int i = 0; i < k; i++)
    {
        low.insert(arr[i]);
        if(low.size() > (k+1)/2){
            high.insert(*low.rbegin());
            low.erase(low.find(*low.rbegin()));
        }
    }
    cout<<*low.rbegin()<<" ";
    for (int i = k; i < n; i++)
    {
        erase(i-k,arr);
        insert(i,arr,k);
        cout<<*low.rbegin()<<" ";
    }
    cout<<endl;
}