#include<bits/stdc++.h>
using namespace std;

int n,a[100];

void solve(int n){
    if(n > 0){
        cout << "[";
        for(int i = 1 ; i < n ; i++) cout << a[i] << " ";
        cout << a[n] << "]";
        cout << endl;
        for(int i = 1 ; i < n ; i++) a[i] = a[i] + a[i+1];
        solve(n-1);
    }
}

int main(){
    int t; cin >> t;
    while(t--){
        cin >> n;
        for(int i = 1 ; i <= n ; i++) cin >> a[i];
        solve(n);
    }
    return 0;
}