#include<bits/stdc++.h>
using namespace std;

int tplt_goc;
int v,e,x,y;
vector<int> adj[2003];
bool check[2003];
vector<pair<int,int>> edge;

void init(){
    memset(adj,0,sizeof(adj));
    memset(check,0,sizeof(check));
    edge.clear();
    for(int i = 0 ; i < e ; i++){
        cin >> x >> y;
        edge.push_back({x,y});  
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
}

void DFS(int u){
    check[u] = 1;
    for(auto v : adj[u]){
        if(!check[v]) DFS(v);
    }
}

int TPLT(){
    int cnt = 0;
    for(int i = 1 ; i <= v ; i++){
        if(!check[i]){
            cnt++;
            DFS(i);
        }
    }
    return cnt;
}

int solve(int i){
    int cnt = 0;
}



int main(){
    int t; cin >> t;
    while(t--){
        init();
        tplt_goc = TPLT();
        vector<pair<int,int>> ans;
        for(int i = 0 ; i < e ; i++){
            if(solve(i) < tplt_goc) ans.push_back(edge[i]);
        }
        sort(edge.begin(),edge.end());
        for(auto it : edge){
            cout << it.first << " " << it.second << " ";
        }
        cout << endl;
    }
}