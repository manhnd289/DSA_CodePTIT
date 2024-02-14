#include<bits/stdc++.h>
using namespace std;

int n;
int a[1000001];
int check[100];

void Try(int i){
    for(int j = 1 ; j <= n ; j++){
        if(!check[j]){
            check[j] = 1;
            a[i] = j;
            if(abs(a[i]-a[i-1]) != 1){
                if(i==n){
                    for(int i = 1 ; i <= n ; i++) cout << a[i];
                    cout << endl;
                }else Try(i+1);
            }
            check[j] = 0;
        }
    }
}

int main(){
    int t; cin >> t;
    while(t--){
        cin >> n;
        a[0] = -1;
        Try(1);
    }
    return 0;
}