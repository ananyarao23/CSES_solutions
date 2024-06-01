#include <bits/stdc++.h>
using namespace std;

bool comp(pair<int,int> a, pair<int,int> b){
    return a.first < b.first;
}
    
int main(){
    int n; cin >> n;
    vector<pair<int,int>> arr(n,{0,0});
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i].first;
        arr[i].second = i;
    }
    sort(arr.begin(),arr.end(),comp);
    int cnt = 0;
    // for (int i = 0; i < n; i++)
    // {
    //     cout<<arr[i].first<<"_"<<arr[i].second<<" ";
    // }
    // cout<<endl;
    for (int i = 1; i < n; i++)
    {
        if(arr[i].second < arr[i-1].second){
            // cout<<"arr["<<i<<"].second("<<arr[i].second<<") is different from arr["<<i-1<<"].second("<<arr[i-1].second<<")"<<endl;
            cnt++;
        }
    }
    cnt++;
    cout<<cnt<<endl;
}