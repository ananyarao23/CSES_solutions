#include <bits/stdc++.h>
using namespace std;
    
#define ll long long
    
int main(){
    string s; cin >> s;
    int l = s.length();
    string ans = "";
    int last_nd = -1;
    for(int i=0;i<l;i++){
        if(int(s[i]) < 58 && int(s[i]) > 47){
            if(ans.length() == 0) continue;
            ans.pop_back();
        }
        else{
            ans.push_back(s[i]);
        }
    }
    cout<<ans<<endl;
    return 1;
}