// Ma tran ke sang danh sach ke
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    int a[n+1][n+1];
    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= n ; j++){
            cin >> a[i][j];
        }
    }
    vector<int> adj[2003];
    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= n ; j++){
            if(a[i][j]){
                adj[i].push_back(j);
            }
        }
    }
    for(int i = 1 ; i <= n ; i++){
        for(int j = 0 ; j < adj[i].size() ; j++){
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }
}