#include<bits/stdc++.h>
using namespace std;

int n,m,x,y,cnt,st,fi;
vector<int> adj[2003];
int tplt[2003];

void init(){
    memset(tplt,0,sizeof(tplt));
    memset(adj,0,sizeof(adj));
    cin >> n >> m;
    for(int i = 0 ; i < m ; i++){
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
}

void dfs(int u){
    tplt[u] = cnt;
    for(int v : adj[u]){
        if(!tplt[v]) dfs(v);
    }
}

int main(){
    int t; cin >> t;
    while(t--){
        init();
        cnt = 1;
        for(int i = 1 ; i <= n ; i++){
            if(!tplt[i]){
                dfs(i);
                cnt++;
            }
        }
        int q; cin >> q;
        while(q--){
            cin >> st >> fi;
            if(tplt[st] == tplt[fi]) cout << "YES" << endl;
            else cout << "NO" << endl;
        }
    }
}