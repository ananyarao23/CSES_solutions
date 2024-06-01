#include <bits/stdc++.h>
using namespace std;
    
int main(){
    int n; cin >> n;
    vector<int> songs;
    for (int i = 0; i < n; i++)
    {
        int x; cin >> x;
        songs.push_back(x);
    }
    map<int,int> inList;
    int first_song = 0;
    inList[songs[0]] = 1;
    int last_song = 0;
    int max_len = 0;
    for (int i = 1; i < n; i++)
    {
        if(inList[songs[i]] == 0){
            last_song++;
            inList[songs[i]] = 1;
        }
        else{
            int len = last_song-first_song+1;
            if(len > max_len) max_len = len;
            while(songs[first_song] != songs[i]) first_song++;
            first_song++;
        }
    }
    if((last_song-first_song+1) > max_len) max_len = last_song-first_song+1;
    cout<<max_len<<endl;
}