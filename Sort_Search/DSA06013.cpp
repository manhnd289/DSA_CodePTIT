#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;
    map<int,int> mp;
    int n,x;
    while(t--){
        mp.clear();
        cin >> n >> x;
        int tmp;
        for(int i = 0 ; i < n ; i++){
            cin >> tmp;
            if(tmp == x) mp[x]++;
        }
        if(mp[x]) cout << mp[x] << endl;
        else cout << -1 << endl;
    }
}