#include<bits/stdc++.h>
using namespace std;

int v,e,x,y,st,fi;
vector<int> adj[2003];
int color[2003];
int parent[2003];

void init(){
    memset(color,0,sizeof(color));
    memset(parent,0,sizeof(parent));
    memset(adj,0,sizeof(adj));
    cin >> v >> e;
    for(int i = 0 ; i < e ; i++){
        cin >> x >> y;
        adj[x].push_back(y);
    }
}

bool dfs(int u){
    color[u] = 1;
    for(int v : adj[u]){
        if(!color[v]){
            if(dfs(v)) return 1;
        }else if(color[v] == 1) return 1;
    }
    color[u] = 2;
    return 0;
}

int main(){
    int t; cin >> t;
    while(t--){
        init();
        bool check1 = 0;
        for(int i = 1 ; i <= v ; i++){
            if(!color[i]){
                if(dfs(i)){
                    cout << "YES" << endl;
                    check1 = 1;
                    break;
                }
            }
        }
        if(!check1) cout << "NO" << endl;
    }
}