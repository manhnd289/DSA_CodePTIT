#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll a,b;

ll solve(ll a, ll b){
    if(b == 0) return 1;
    ll tmp = solve(a,b/2);
    if(b % 2 == 1) return ((tmp*tmp%(ll)(1e9+7))*a)%(ll)(1e9+7);
    else return (tmp % (ll)(1e9+7) * tmp % (ll)(1e9+7)) % (ll)(1e9+7);
}

int main(){
    int t; cin >> t;
    while(t--){
        cin >> a >> b;
        if(a==0 && b==0) break;
        cout << solve(a,b) << endl;
    }
    return 0;
}