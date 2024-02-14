#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        queue<ll> q;
        q.push(1);
        ll res = 1;
        while(!q.empty()){
            ll tmp = q.front(); q.pop();
            ll tmp1 = tmp*10;
            if(tmp1 % n == 0) {res = tmp1; break;}
            q.push(tmp1);
            tmp1 = tmp*10+1;
            if(tmp1 % n == 0) {res = tmp1; break;}
            q.push(tmp1);
        }
        cout << res << endl;
    }
}