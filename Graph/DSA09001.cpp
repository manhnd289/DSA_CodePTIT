#include<bits/stdc++.h>
using namespace std;

int n,m,x,y;
vector<int> adj[2003];

void init(){
    memset(adj,0,sizeof(adj));
    cin >> n >> m;
    for(int i = 0 ; i < m ; i++){
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
}

void solve(){
    for(int i = 1 ; i <= n ; i++){
        cout << i << ": ";
        for(int j = 0 ; j < adj[i].size() ; j++){
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }
}

int main(){
    int t; cin >> t;
    while(t--){
        init();
        solve();
    }
}