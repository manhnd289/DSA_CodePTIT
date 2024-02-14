#include<bits/stdc++.h>
using namespace std;

int v,e,x,y;
bool check[2003];
vector<int> adj[2003];

void init(){
    memset(adj,0,sizeof(adj));
    memset(check,0,sizeof(check));
    cin >> v >> e;
    for(int i = 0 ; i < e ; i++){
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
}

void dfs(int u){
    check[u] = 1;
    for(int v : adj[u]){
        if(!check[v]) dfs(v);
    }
}

void dinh_tru(){
    int tplt = 0;
    int cnt = 0;
    for(int i = 1 ; i <= v ; i++){
        if(!check[i]){
            dfs(i);
            tplt++;
        }
    }
    for(int i = 1 ; i <= v ; i++){
        memset(check,0,sizeof(check));
        cnt = 0;
        check[i] = 1;
        for(int j = 1 ; j <= v ; j++){
            if(!check[j]){
                dfs(j);
                cnt++;
            }
        }
        if(cnt > tplt) cout << i << " ";
    }
}

int main(){
    int t; cin >> t;
    while(t--){
        init();
        dinh_tru();
        cout << endl;
    }
}