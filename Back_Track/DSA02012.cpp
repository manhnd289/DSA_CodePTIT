#include<bits/stdc++.h>
using namespace std;
#define ll long long

int m,n;
int a[100][100];
ll cnt = 0;

void init(){
    memset(a,0,sizeof(a));
    cnt = 0;
    cin >> m >> n;
    for(int i = 1 ; i <= m ; i++){
        for(int j = 1 ; j <= n ; j++){
            cin >> a[i][j];
        }
    }
}

void solve(int i,int j){
    if(i == m && j == n){
        cnt++;
    }
    if(i <= m) solve(i+1,j);
    if(j <= n) solve(i,j+1);
}

int main(){
    int t; cin >> t;
    while(t--){
        init();
        solve(1,1);
        cout << cnt << endl;
    }
    return 0;
}