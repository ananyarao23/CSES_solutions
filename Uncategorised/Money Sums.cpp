#include <bits/stdc++.h>
using namespace std;

#define MAXSIZE 100000
    
int main(){
    int n; cin >> n;
    int x[n];
    for (int i = 0; i < n; i++)
    {
        cin >> x[i];
    }
    vector<int> cnt(MAXSIZE,0);
    vector<int> sum;
    int sz;
    for (int i = 0; i < n; i++)
    {
        sz = sum.size();
        for (int j = 0; j < sz; j++)
        {
            if(cnt[sum[j]+x[i]] > 0) continue;
            sum.push_back(sum[j]+x[i]);
            cnt[sum[j]+x[i]]++;
        }
        if(cnt[x[i]] == 0){
            sum.push_back(x[i]);
            cnt[x[i]]++;
        }
    }
    sort(sum.begin(),sum.end());
    cout<<sum.size()<<endl;
    for (auto c:sum)
    {
        cout<<c<<" ";
    }
    
}