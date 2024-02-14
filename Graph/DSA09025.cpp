#include<bits/stdc++.h>
using namespace std;

int n,m,x,y,st,fi;
vector<int> adj[2003];
bool check[2003];
int parent[2003];
stack<int> s;

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

void dfs(int u){
    check[u] = 1;
    s.push(u);
    while(!s.empty()){
        int v = s.top(); s.pop();
        for(int x : adj[v]){
            if(!check[x]){
                check[x] = 1;
                parent[x] = v;
                s.push(v);
                s.push(x);
                break;
            }
        }
    }

}

void findPath(){
    dfs(st);
    if(!parent[fi]) cout << -1;
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
}

int main(){
    int t; cin >> t;
    while(t--){
        init();
        findPath();
        cout << endl;
    }
}