#include<bits/stdc++.h>
using namespace std;

int t,n,m,x,y;
int cnt; 
vector<int> g[2003];
vector<int> tg[2003];
bool check[2003];
stack<int> topo; 

void init(){
	memset(check,0,sizeof(check));
	for(int i = 0 ; i < 2003 ; i++){
		g[i].clear();
		tg[i].clear();
	}
	cin >> n >> m;
	for(int i = 0 ; i < m ; i++){
		cin >> x >> y;
		g[x].push_back(y);
		tg[y].push_back(x);
	}
}

void DFS(int u){
	check[u] = 1;
	for(int v : tg[u]){
		if(!check[v]) DFS(v);
	}
}

void Topo(int u){
	check[u] = 1;
	for(int v : g[u]){
		if(!check[v]){
			Topo(v);
		}
	}
	topo.push(u);
}

void SCC_Kosaraju(){
	for(int i = 1 ; i <= n ; i++){
		if(!check[i]) Topo(i);
	}
	memset(check,0,sizeof(check));
	cnt = 0;
	while(!topo.empty())
	{
		int tmp = topo.top(); topo.pop();
		if(!check[tmp]){
			DFS(tmp);
			cout << endl;
			cnt++;
		}
	}
}

int main(){
	cin >> t;
	while(t--){
		init();
		SCC_Kosaraju();
		if(cnt == 1) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
}
