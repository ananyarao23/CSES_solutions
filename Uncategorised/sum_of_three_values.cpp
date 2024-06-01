#include <bits/stdc++.h>
using namespace std;

bool custom_comp(pair<int,int> a,pair<int,int> b){
    return !(a.first > b.first);
}

int main(){
    int n,x;
    scanf("%d%d",&n,&x);
    vector<pair<int,int>> v;
    unordered_map<int,int> m;
    int a,b;
    unordered_map<int,pair<int,int>> ind;
    for (int i = 0; i < n; i++)
    {
        int a; scanf("%d",&a);
        v.push_back({a,i});
    }
    sort(v.begin(),v.end(),custom_comp);
    for (int i = 0; i < n-2; i++)
    {
        int s = x - v[i].first;
        a = i+1;
        b = n-1;
        while (a<n)
        {
            for(;b>a && v[a].first+v[b].first > s;b--);
            // cout<<(v[a].first+v[b].first)<<endl;
            if((v[a].first+v[b].first) == s && v[a].second != i && v[b].second != i && v[a].second != v[b].second){
                cout<<v[i].second+1<<" "<<v[a].second+1<<" "<<v[b].second+1<<endl;
                return 0;
            }
            a++;
        }
        
    }
    
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = i+1; j < n; j++)
    //     {
    //         m[v[i]+v[j]] = 1;
    //         ind[v[i]+v[j]] = {i,j};
    //     }
    // }
    // for (int i = 0; i < n-2; i++)
    // {
    //     if(m[x-(v[i])] == 1 && ind[x-(v[i])].first > i){
    //         cout<<i+1<<" "<<ind[x-(v[i])].first+1<<" "<<ind[x-(v[i])].second+1<<endl;
    //         return 0;
    //     }
    // }
    cout<<"IMPOSSIBLE"<<endl;
    return 0;
}