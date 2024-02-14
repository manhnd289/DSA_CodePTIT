#include<bits/stdc++.h>
using namespace std;

int v,e,x,y;
vector<int> adj[2003];
bool check[2003];
vector<int> res;

void init(){
    memset(check,0,sizeof(check));
    memset(adj,0,sizeof(adj));
    res.clear();
    cin >> v >> e;
    for(int i = 0 ; i < e ; i++){
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
}

void DFS1(int u){
    check[u] = 1;
    for(int v : adj[u]){
        if(!check[v]) DFS1(v);
    }
}

void dinh_tru(){
    int tplt = 0;
    for(int i = 1 ; i <= v ; i++){
        if(!check[i]){
            DFS1(i); tplt++;
        }
    }
    int cnt = 0;
    for(int i = 1 ; i <= v ; i++){
        cnt = 0;
        memset(check,0,sizeof(check));
        check[i] = 1;
        for(int j = 1 ; j <= v ; j++){
            if(!check[j]){
                DFS1(j); cnt++;
            }
        }
        if(cnt > tplt) res.push_back(i);
    }
}

int main(){
    int t; cin >> t;
    while(t--){
        init();
        dinh_tru();
        for(int x : res) cout << x << " ";
        cout << endl;
    }
}