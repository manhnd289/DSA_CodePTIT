#include<bits/stdc++.h>
using namespace std;

int v,e,x,y;
int parent[2003];
bool check[2003];
vector<int> adj[2003];

void init(){
    memset(check,0,sizeof(check));
    memset(adj,0,sizeof(adj));
    memset(parent,0,sizeof(parent));
    cin >> v >> e;
    for(int i = 0 ; i < e ; i++){
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
}

bool dfs(int u){
    check[u] = 1;
    for(int v : adj[u]){
        if(!check[v]){
            parent[v] = u;
            if(dfs(v)) return 1;
        }else if(v != parent[u]) return 1;
    }
    return 0;
}

int main(){
    int t; cin >> t;
    while(t--){
        init();
        for(int i = 1 ; i <= v ; i++){
            sort(adj[i].begin(),adj[i].end());
        }
        bool check1 = 0;
        for(int i = 1 ; i <= v ; i++){
            if(!check[i]){
                parent[i] = 0;
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