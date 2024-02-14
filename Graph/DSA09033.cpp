#include<bits/stdc++.h>
using namespace std;

int v,e,x,y;
vector<int> adj[200003];
bool check[200003];
vector<int> tplt;

void init(){
    memset(check,0,sizeof(check));
    memset(adj,0,sizeof(adj));
    tplt.clear();
    cin >> v >> e;
    for(int i = 1 ; i <= e ; i++){
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
}

void BFS(int u){
    tplt.push_back(u); //Xây dựng các thành phần trong thành phần liên thông đỉnh đó
    check[u] = 1;
    queue<int> q;
    q.push(u);
    while(!q.empty()){
        int tmp = q.front(); q.pop();
        for(int x : adj[tmp]){
            if(!check[x]){
                tplt.push_back(x); //Xây dựng thành phần liên thông
                check[x] = 1;
                q.push(x);
            }
        }
    }
}

int main(){
    int t; cin >> t;
    while(t--){
        bool ok = 1; 
        init();
        for(int i = 1 ; i <= v ; i++){
            if(!check[i]){
                tplt.clear();
                BFS(i);
                for(int x : tplt){
                    //Kiểm tra xem số đỉnh kề của 1 đỉnh trong thành phần liên thông đó
                    //có bằng số lượng đỉnh trong thành phần liên thông hiện tại mà trừ đi đỉnh đó không
                    if(adj[x].size() != tplt.size() - 1){
                        ok = 0;
                        break;
                    }
                }
            }
            if(!ok) break; // Nếu 1 tplt không thỏa mãn thoát luôn
        }
        cout << (ok ? "YES" : "NO") << endl;
    }
}