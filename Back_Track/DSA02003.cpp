#include<bits/stdc++.h>
using namespace std;

int n,a[100][100];
vector<string> v;
bool checkPath = 0;

void init(){
    cin >> n;
    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= n ; j++) cin >> a[i][j];
    }
    v.clear();
    checkPath = 0;
}

void Try(int i, int j, string s){
    if(!a[1][1] || !a[n][n]){
        checkPath = 0;
        return;
    }
    if(i == n && j == n && a[i][j]){
        v.push_back(s);
        checkPath = 1;
        return;
    }
    if(i<=n && a[i+1][j]) Try(i+1,j,s+"D");
    if(j<=n && a[i][j+1]) Try(i,j+1,s+"R");
    if(i>n || j>n || (i<n && j<n && !a[i+1][j] && a[i][j+1])) return;
}

int main(){
    int t; cin >> t;
    while(t--){
        init();
        Try(1,1,"");
        if(!checkPath) cout << "-1" << endl;
        else{
            sort(v.begin(),v.end());
            for(auto x : v) cout << x << " ";
            cout << endl;
        }
        
    }
    return 0;
}