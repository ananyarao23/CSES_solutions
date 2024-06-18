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
    int num[n];
    ll max_num = -1;
    vector<ll> count(1000001);
    for (int i = 0; i < n; i++)
    {
        cin >> num[i];
        if(num[i] > max_num) max_num = num[i];
        count[num[i]]++;
    }
    for (int i = max_num; i >= 1; i--)
    {
        int cnt = 0;
        for(int j = i;j<=max_num;j += i){
            cnt += count[j];
        }
        if(cnt > 1){
            cout<<i<<endl;
            break;
        }
    }
}