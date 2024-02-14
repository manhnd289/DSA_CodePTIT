// Truy vet duong di BFS
#include<bits/stdc++.h>
using namespace std;

int v,e,x,y,st,fi;
vector<int> adj[2003];
bool check[2003];
int parent[2003];
queue<int> q;

void init(){
    memset(parent,0,sizeof(parent));
    memset(check,0,sizeof(check));
    memset(adj,0,sizeof(adj));
    cin >> v >> e >> st >> fi;
    for(int i = 0 ; i < e ; i++){
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
}

void BFS(int u){
    check[u] = 1;
    q.push(u);
    while(!q.empty()){
        int v = q.front(); q.pop();
        for(int x : adj[v]){
            if(!check[x]){
                parent[x] = v;
                check[x] = 1;
                q.push(x);
            }
        }
    }
}

void findPath(){
    BFS(st);
    if(!parent[fi]) cout << -1 << endl;
    else{
        vector<int> tmp;
        while(fi!=st){
            tmp.push_back(fi);
            fi = parent[fi];
        }
        tmp.push_back(st);
        reverse(tmp.begin(),tmp.end());
        for(int x : tmp) cout << x << " ";
    }
    cout << endl;
}

int main(){
    int t; cin >> t;
    while(t--){
        init();
        findPath();
    }
}