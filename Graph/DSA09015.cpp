#include<bits/stdc++.h>
using namespace std;

int v,e,x,y;
int degree[2003];
vector<int> adj[2003];
queue<int> q;

void init(){
    memset(degree,0,sizeof(degree));
    memset(adj,0,sizeof(adj));
    cin >> v >> e;
    for(int i = 0 ; i < e ; i++){
        cin >> x >> y;
        adj[x].push_back(y);
        degree[y]++;
    }
}

bool kahn(){
    int cnt = 0;
    for(int i = 1 ; i <= v ; i++){
        if(!degree[i]) q.push(i);
    }
    while(!q.empty()){
        int v = q.front(); q.pop();
        cnt++;
        for(int x : adj[v]){
            degree[x]--;
            if(!degree[x]) q.push(x);
        }
    }
    return cnt != v;
}

int main(){
    int t; cin >> t;
    while(t--){
        init();
        if(kahn()) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}