#include<bits/stdc++.h>
using namespace std;

int v,e,x,y;
set<int> adj[2003];
int degree[2003];

void init(){
    memset(degree,0,sizeof(degree));
    for(int i = 0 ; i < 2003 ; i++) adj[i].clear();
    cin >> v >> e;
    for(int i = 0 ; i < e ; i++){
        cin >> x >> y;
        adj[x].insert(y);
        adj[y].insert(x);
        degree[x]++; degree[y]++;
    }
}

int euler(int u){
    int cnt = 0;
    for(int i = 1 ; i <= v ; i++) if(degree[i] % 2 == 1) cnt++;
    if(cnt == 0) return 2;
    else if(cnt == 2) return 1;
    return 0;
}

int main(){
    int t; cin >> t;
    while(t--){
        init();
        int a = euler(3);
        cout << a << endl;
    }
}