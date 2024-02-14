#include<bits/stdc++.h>
using namespace std;

int n,m;
char a[2003][2003];
bool check[2003][2003];
int X[8] = {-1,-1,-1,0,0,1,1,1};
int Y[8] = {-1,0,1,-1,1,-1,0,1};

void init(){
    memset(check,0,sizeof(check));
    cin >> n >> m;
    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= m ; j++){
            cin >> a[i][j];
        }
    }
}

void dfs(int i,int j){
    check[i][j] = 1;
    for(int t = 0 ; t < 8 ; t++){
        int x = i + X[t];
        int y = j + Y[t];
        if(x >= 1 && y >= 1 && x <= n && y <= m && !check[x][y] && a[x][y] == 'W') dfs(x,y);
    }
}

int Solve(){
    int cnt = 0;
    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= m ; j++){
            if(!check[i][j] && a[i][j] == 'W'){
                dfs(i,j);
                cnt++;
            }
        }
    }
    return cnt;
}

int main(){
    init();
    cout << Solve() << endl;
}