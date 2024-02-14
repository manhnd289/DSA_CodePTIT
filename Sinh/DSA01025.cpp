#include<bits/stdc++.h>
using namespace std;

int n,k;
int a[203];

void out(){
    for(int j = 1 ; j <= k ; j++){
        cout << char(a[j] + 64);
    }
    cout << endl;
}

void Try(int i){
    for(int j = a[i-1]+1 ; j <= n-k+i ; j++){
        a[i] = j;
        if(i == k) out();
        else Try(i+1);
    }
}

int main(){
    int t; cin >> t;
    while(t--){
        cin >> n >> k;
        a[0] = 0;
        Try(1);
    }
}