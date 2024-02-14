#include<bits/stdc++.h>
using namespace std;

int n,m,x,y,st,fi;
bool check[2003];
vector<int> adj[2003];
int parent[2003];
queue<int> q;

void init(){
    memset(check,0,sizeof(check));
    memset(adj,0,sizeof(adj));
    memset(parent,0,sizeof(parent));
    cin >> n >> m >> st >> fi;
    for(int i = 0 ; i < m ; i++){
        cin >> x >> y;
        adj[x].push_back(y);
    }
}

void bfs(int u){
    check[u] = 1;
    q.push(u);
    while(!q.empty()){
        int v = q.front(); q.pop();
        for(int x : adj[v]){
            if(!check[x]){
                check[x] = 1;
                q.push(x);
                parent[x] = v;
            }
        }
    }
}

void findPath(){
    bfs(st);
    if(!parent[fi]) cout << -1;
    else{
        vector<int> tmp;
        while(fi!=st){
            tmp.push_back(fi);
            fi = parent[fi];
        }
        tmp.push_back(st);
        reverse(tmp.begin(), tmp.end());
        for(int x : tmp) cout << x << " ";
    }
}

int main(){
    int t; cin >> t;
    while(t--){
        init();
        findPath();
        cout << endl;
    }
}
