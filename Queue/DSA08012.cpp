#include<bits/stdc++.h>
using namespace std;

bool check(int n,int i){
    string s = to_string(n);
    map<char,int> mp;
    for(char c : s) mp[c]++;
    if(mp[i+48] == 0) return 1;
    return 0;
}

void solve(int a,int b){
    int cnt = 0;
    if(a == 0) cnt = 1;
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    while(!q.empty()){
        int tmp = q.front(); q.pop();
        if(tmp >= a && tmp <= b) cnt++;
        for(int i = 0 ; i <= 5 ; i++){
            if(check(tmp,i) && tmp*10+i <= b) q.push(tmp*10+i);
        }
    }
    cout << cnt << endl;
}

int main(){
    int t; cin >> t;
    while(t--){
        int a,b; cin >> a >> b;
        solve(a,b);
    }
}