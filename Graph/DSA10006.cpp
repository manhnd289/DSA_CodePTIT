#include<bits/stdc++.h>
using namespace std;

int v,e,x,y,st;
vector<int> adj[2003];
bool check[2003];
vector<int> tree;
int parent[2003];

void init(){
    tree.clear();
    memset(parent,0,sizeof(parent));
    memset(check,0,sizeof(check));
    memset(adj,0,sizeof(adj));
    cin >> v >> e >> st;
    for(int i = 0 ; i < e ; i++){
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
}

void DFS(int u){
    tree.push_back(u);
    check[u] = 1;
    for(int v : adj[u]){
        if(!check[v]){
            parent[v] = u;
            DFS(v);
        }
    }
}

void spanning_tree(int u){
    DFS(u);
    if(tree.size() != v){
        cout << -1 << endl; return;
    }
    for(int i = 1 ; i < tree.size() ; i++){
        cout << parent[tree[i]] << " " << tree[i] << endl;
    }
}

int main(){
    int t; cin >> t;
    while(t--){
        init();
        spanning_tree(st);
    }
}