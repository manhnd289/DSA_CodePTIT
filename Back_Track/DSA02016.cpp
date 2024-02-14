#include<bits/stdc++.h>
using namespace std;

int n;
int cnt = 0;
int a[100],col[100],d1[100],d2[100];

void init(){
    memset(col,0,sizeof(col));
    memset(d1,0,sizeof(d1));
    memset(d2,0,sizeof(d2));
    cin >> n;
}

void Try(int i){
    for(int j = 1 ; j <= n ; j++){
        if(!col[j] && !d1[i-j+n] && !d2[i+j-1]){
            a[i] = j;
            col[j] = d1[i-j+n] = d2[i+j-1] = 1;
            if(i == n) cnt++;
            else Try(i+1);
            col[j] = d1[i-j+n] = d2[i+j-1] = 0;
        }
    }
}

int main(){
    int t; cin >> t;
    while(t--){
        cnt = 0;
        init();
        Try(1);
        cout << cnt << endl;
    }
}