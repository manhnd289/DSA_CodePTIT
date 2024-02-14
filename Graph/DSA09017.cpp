#include<bits/stdc++.h>
using namespace std;

int n,x,y;
bool ok = 1;
bool check[2003];

void init(){
    memset(check,0,sizeof(check));
    ok = 1;
    cin >> n;
    for(int i = 1 ; i <= n-1 ; i++){
        cin >> x >> y;
        if(check[x] && check[y]) ok = 0;
        check[x] = check[y] = 1;
    }
}

int main(){
    int t; cin >> t;
    while(t--){
        init();
        cout << (ok ? "YES" : "NO") << endl;
    }
}