#include<bits/stdc++.h>
using namespace std;

int n,m,x,y,st;
vector<int> adj[2003];
bool check[2003];
stack<int> st;

void init(){
    memset(check,0,sizeof(check));
    memset(adj,0,sizeof(adj));
    cin >> n >> m >> st;
    for(int i = 0 ; i < m ; i++){
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
}

void dfs(int u){
    check[u] = 1;
    cout << u << " ";
    for(int v : adj[u]){
        if(!check[v]) dfs(v);
    }
}

int main(){
    int t; cin >> t;
    while(t--){
        init();
        dfs(st);
        cout << endl;
    }
}