#include<bits/stdc++.h>
using namespace std;

int n,k;
int a[100];

void Try(int i){
    for(int j = 0 ; j <= 1 ; j++){
        a[i] = j;
        if(i == n){
            int cnt = 0;
            for(int i = 1 ; i <= n; i++) if(a[i]) cnt++;
            if(cnt == k){
                for(int i = 1 ; i <= n ; i++) cout << a[i];
                cout << endl;
            }
        }else Try(i+1);
    }
}

int main(){
    int t; cin >> t;
    while(t--){
        cin >> n >> k;
        Try(1);
    }
}