#include<bits/stdc++.h>
using namespace std;

int n,m,x,y,u;
vector<int> adj[2003];
bool check[2003];
stack<int> st;

void init(){
    memset(check,0,sizeof(check));
    memset(adj,0,sizeof(adj));
    cin >> n >> m >> u;
    for(int i = 0 ; i < m ; i++){
        cin >> x >> y;
        adj[x].push_back(y);
    }
}

void dfs(int u){
    check[u] = 1;
    cout << u << " ";
    st.push(u);
    while(!st.empty()){
        int v = st.top(); st.pop();
        for(int x : adj[v]){
            if(!check[x]){
                check[x] = 1;
                cout << x << " ";
                st.push(v);
                st.push(x);
                break;
            }
        }
    }

}

int main(){
    int t; cin >> t;
    while(t--){
        init();
        dfs(u);
        cout << endl;
    }
}