#include<bits/stdc++.h>
using namespace std;

int a[203];
int n;

void Try(int i){
    for(int j = 0 ; j <= 1 ; j++){
        a[i] = j;
        if(i == n){
            if(a[1] && !a[n]){
                bool check1 = 1;
                for(int k = 1 ; k < n ; k++) if(a[k] && a[k+1]) check1 = 0;
                if(check1){
                    bool check2 = 1;
                    for(int k = 1 ; k <= n-3 ; k++) if(!a[k] && !a[k+1] && !a[k+2] && !a[k+3]) check2 = 0;
                    if(check2){
                        for(int k = 1 ; k <= n ; k++){
                            if(a[k]) cout << 8;
                            else cout << 6;
                        }
                        cout << endl;
                    }
                }
            }
        }
        else Try(i+1);
    }
}

int main(){
    cin >> n;
    Try(1);
}