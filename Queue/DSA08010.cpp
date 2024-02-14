#include<bits/stdc++.h>
using namespace std;

int BFS(int n){
    queue<pair<int,int>> q;
    map<int,bool> mp; // Check xem đã xuất hiện hay chưa
    q.push({n,0});
    while(!q.empty()){
        auto tmp = q.front(); q.pop();
        if(tmp.first == 2) return tmp.second+1;
        // Có thể không cần điều kiện vì đã bị chặn bởi 2 bên trên
        if(mp[tmp.first-1] == 0) q.push({tmp.first-1,tmp.second+1});
        // Điều kiện chưa xuất hiện để tránh bị lặp
        for(int i = 2 ; i <= sqrt(tmp.first) ; i++){
            if(tmp.first % i == 0 && mp[tmp.first/i] == 0){
                q.push({tmp.first/i , tmp.second+1});
                mp[tmp.first/i] = 1;
            }
        }
        
    }
}

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        cout << BFS(n) << endl;
    }
}