#include<bits/stdc++.h>
using namespace std;

int n,m;
int a[1005][1005];
int dp[1005][1005];

void BFS(int i,int j){
    dp[i][j] = 0;
    queue<pair<int,int>> q;
    q.push({i,j});
    while(!q.empty()){
        auto tmp = q.front(); q.pop();
        int u = tmp.first; 
        int v = tmp.second;
        if(u == n && v == m) return;
        if(dp[u][v + a[u][v]] == 0 && v + a[u][v] <= m){
            dp[u][v + a[u][v]] = dp[u][v] + 1;
            q.push({u, v + a[u][v]});
        }
        if(dp[u + a[u][v]][v] == 0 && u + a[u][v] <= n){
            dp[u + a[u][v]][v] = dp[u][v] + 1;
            q.push({u + a[u][v],v});
        }
    }
    return;
}

int main(){
    int t; cin >> t;
    while(t--){
        cin >> n >> m;
        for(int i = 1 ; i <= n ; i++){
            for(int j = 1 ; j <= m ; j++) cin >> a[i][j];
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                dp[i][j] = 0;
            }
        }
        BFS(1,1);
        cout << ((dp[n][m] == 0) ? -1 : dp[n][m]) << endl;
    }
}