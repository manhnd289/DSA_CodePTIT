#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve(int n){
    queue<ll> q;
    vector<ll> res;
    q.push(6);
    q.push(8);
    while(!q.empty()){
        ll tmp = q.front(); q.pop();
        res.push_back(tmp);
        if(to_string(tmp).size() == n) continue;
        q.push(tmp*10+6);
        q.push(tmp*10+8);
    }
    cout << res.size() << endl;
    for(int i = 0 ; i < res.size() ; i++){
        cout << res[i] << " ";
    }
    cout << endl;
}

int main(){
    int n;
    int t; cin >> t;
    while(t--){
        cin >> n;
        solve(n);
    }
}