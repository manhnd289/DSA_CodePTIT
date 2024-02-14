#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    int t; cin >> t;
    while(t--){
        int x; cin >> x;
        queue<ll> q;
        q.push(9);
        while(!q.empty()){
            ll tmp = q.front(); q.pop();
            if(tmp % x == 0){
                cout << tmp << endl;
                break;
            }
            q.push(tmp*10);
            q.push(tmp*10 + 9);
        }

    }
}