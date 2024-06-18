#include <bits/stdc++.h>
using namespace std;
    
#define ll long long
    
int main(){
    string s;
    cin >> s;
    string mapping = "ACGT";
    ll letter[4]; // 0 - A, 1 - C, 2 - G, 3 - T
    for (int i = 0; i < 4; i++) letter[i] = 0;
    for(auto c:s){
        if(c == 'A') letter[0]++;
        if(c == 'C') letter[1]++;
        if(c == 'G') letter[2]++;
        if(c == 'T') letter[3]++;
    }
    string ans = "";
    ll ptr = 0;
    while(true){
        char c;
        ll min_count = 1000000000;
        for(int i=0;i<4;i++){
            if(letter[i] < min_count){
                min_count = letter[i];
                c = mapping[i];
            }
        }
        if(min_count == 0){
            ans.push_back(c);
            break;
        }
        for(;s[ptr] != c;ptr++){
            if(s[ptr] == 'A') letter[0]--;
            if(s[ptr] == 'C') letter[1]--;
            if(s[ptr] == 'G') letter[2]--;
            if(s[ptr] == 'T') letter[3]--;
        }
        ans.push_back(c);
        ptr++;
        if(c == 'A') letter[0]--;
        if(c == 'C') letter[1]--;
        if(c == 'G') letter[2]--;
        if(c == 'T') letter[3]--;
    }
    cout<<ans<<endl;
}