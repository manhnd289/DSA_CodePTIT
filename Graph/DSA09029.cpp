#include<bits/stdc++.h>
using namespace std;

int ok = 0;
int v,e,x,y;
vector<int> adj[2003];
bool check[2003];

void init(){
    memset(adj,0,sizeof(adj));
    memset(check,0,sizeof(check));
    ok = 0;
    cin >> v >> e;
    for(int i = 1 ; i <= e ; i++){
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
}

void dfs(int u,int cnt){
    if(cnt == v) ok = 1;
    if(ok) return;
    for(int x : adj[u]){
        if(!check[x]){
            check[x] = 1;
            dfs(x, cnt+1);
            check[x] = 0;
        }
    }
}

int main(){
    int t; cin >> t;
    while(t--){                                              
        init();            
        for(int i = 1 ; i <= v ; i++){
            memset(check,0,sizeof(check));
            check[i] = 1;
            dfs(i,1);
            if(ok) break;
        }
        cout << (ok ? 1 : 0) << endl;
    }
}