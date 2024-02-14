#include<bits/stdc++.h>
using namespace std;
#define ll long long

int v,e,x,y,w,q,s,f;
ll a[2003][2003];

void init(){
    cin >> v >> e;
    for(int i = 1 ; i <= v ; i++){
        for(int j = 1 ; j <= v ; j++){
            a[i][j] = INT_MAX;
        }
    }
    for(int i = 0 ; i < e ; i++){
        cin >> x >> y >> w;
        a[x][y] = a[y][x] = w;
    }
    for(int i = 1 ; i <= v ; i++){
        for(int j = 1 ; j <= v ; j++){
            if(i == j) a[i][j] = 0;
        }
    }
    cin >> q;
}

void solve(){
    for(int i = 1 ; i <= v ; i++){
        for(int j = 1 ; j <= v ; j++){
            for(int k = 1 ; k <= v ; k++){
                if((j == i && k == i) || (k == j)) continue;
                else a[j][k] = min(a[j][k],a[j][i] + a[i][k]);
            }
        }
    }
}

int main(){
    init();
    solve();
    while(q--){
        cin >> s >> f;
        cout << a[s][f] << endl;
    }
}