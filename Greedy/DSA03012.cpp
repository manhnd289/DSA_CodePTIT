#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;
    map<char,int> mp;
    string s;
    int n,max_freq;
    while(t--){
        mp.clear();
        max_freq = -1e9;
        cin >> s;
        n = s.size();
        for(int i = 0 ; i < n ; i++) mp[s[i]]++;
        for(auto it : mp){
            if(it.second > max_freq) max_freq = it.second;
        }
        if(n - max_freq >= max_freq-1) cout << 1 << endl;
        else cout << -1 << endl;
    }
}