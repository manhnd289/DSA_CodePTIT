#include<bits/stdc++.h>
using namespace std;
#define ll long long

bool check(string s){
    ll tmp = 0;
    for(char c : s) tmp += c-48;
    if (tmp % 3 == 0) return 1;
    return 0;
}

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int a[n];
        for(int &x : a) cin >> x;
        
    }
}