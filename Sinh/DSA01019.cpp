#include<bits/stdc++.h>
using namespace std;

int n; 
int a[203];

void Try(int i){
    for(int j = 0 ; j <= 1 ; j++){
        a[i] = j;
        if(i == n){
            if(a[1] == 1 && a[n] == 0){
                int i = n-1;
                bool ok = 1;
                for(int i = 1 ; i < n ; i++){
                    if(a[i] == 1 && a[i+1] == 1){
                        ok = 0;
                        break;
                    }
                }
                if(ok){
                    for(int k = 1 ; k <= n ; k++){
                        if(a[k]) cout << 'H';
                        else cout << 'A';
                    }
                    cout << endl;
                }
            }
        }else Try(i+1);
    }
}

int main(){
    int t; cin >> t;
    while(t--){
        cin >> n;
        Try(1);
    }
}