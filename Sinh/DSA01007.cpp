#include<bits/stdc++.h>
using namespace std;

int n; 
int a[203];

void Try(int i){
    for(int j = 0 ; j <= 1 ; j++){
        a[i] = j;
        if(i == n){
            for(int k = 1 ; k <= n ; k++){
                if(a[k] == 0) cout << 'A';
                else cout << 'B';
            }
            cout << " ";
        }
        else Try(i+1);
    }
}

int main(){
    int t; cin >> t;
    while(t--){
        cin >> n;
        Try(1);
        cout << endl;
    }
}