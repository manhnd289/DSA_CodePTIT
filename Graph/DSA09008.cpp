// Dem so thanh phan lien thong
#include<bits/stdc++.h>
using namespace std;

int n,m,x,y;
bool check[2003];
vector<int> adj[2003];
queue<int> q;

void init(){
    memset(adj,0,sizeof(adj));
    memset(check,0,sizeof(check));
    cin >> n >> m;
    for(int i = 0 ; i < m ; i++){
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

// void bfs(int u){
//     check[u] = 1;
//     q.push(u);
//     while(!q.empty()){
//         int v = q.front(); q.pop();
//         for(int x : adj[v]){
//             if(!check[x]){
//                 check[x] = 1;
//                 q.push(x);
//             }
//         }
//     }
// }

int main(){
    int t; cin >> t;
    while(t--){
        init();
        int cnt = 0;
        for(int i = 1 ; i <= n ; i++){
            if(!check[i]){
                dfs(i);
                cnt++;
            }
        }
        cout << cnt << endl;
    }
}