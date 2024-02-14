#include<bits/stdc++.h>
using namespace std;

#define ll long long
const ll mod = 1e9+7;

int a[1000001];

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        for(int i = 0 ; i < n ; i++) cin >> a[i];
        sort(a,a+n);
        ll res = 0;
        for(int i = 0 ; i < n ; i++){
            res += a[i]*i;
            res %= mod;
        }
        cout << res << endl;
    }
    return 0;
}