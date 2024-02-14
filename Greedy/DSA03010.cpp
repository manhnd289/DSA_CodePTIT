#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        ll a[n];
        for(int i = 0 ; i < n ; i++) cin >> a[i];
        sort(a,a+n);
        int res = 0;
        int tmp = a[0];
        for(int i = 0 ; i < n-1 ; i++){
            tmp += a[i+1];
            res += tmp;
        }
        cout << res << endl;
    }
    return 0;
}
