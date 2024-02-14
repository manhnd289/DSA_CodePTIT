#include<bits/stdc++.h>
using namespace std;

int n,m,x,y,u;
vector<int> adj[2003];
bool check[2003];
queue<int> q;

void init(){
	memset(check,0,sizeof(check));
	memset(adj,0,sizeof(adj));
	cin >> n >> m >> u;
	for(int i = 0 ; i < m ; i++){
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
}

void bfs(int u){
	check[u] = 1;
	cout << u << " ";
	q.push(u);
	while(!q.empty()){
		int v = q.front(); q.pop();
		for(int x : adj[v]){
			if(!check[x]){
				check[x] = 1;
				cout << x << " ";
				q.push(x);
			}
		}
	}
}

int main(){
	int t; cin >> t;
	while(t--){
		init();
		bfs(u);
		cout << endl;
	}
}