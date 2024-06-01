#include <bits/stdc++.h>
using namespace std;

// custom comparator
bool comp(vector<int> a,vector<int> b){
    return a[0] < b[0];
}
    
int main(){
    int n; cin >> n;
    vector<vector<int>> ranges(n);
    for (int i = 0; i < n; i++)
    {
        int l,r; cin >> l >> r;
        ranges[i].push_back(l);
        ranges[i].push_back(r);
        ranges[i].push_back(i);
    }
    sort(ranges.begin(),ranges.end(),comp);
    vector<int> a(n,0),b(n,0);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if(ranges[j][1] >= ranges[i][1]){
                a[ranges[j][2]]++;
                b[ranges[i][2]]++;
            }
        }
    }
    for(auto c:a) cout<<c<<" ";
    cout<<endl;
    for(auto c:b) cout<<c<<" ";
}