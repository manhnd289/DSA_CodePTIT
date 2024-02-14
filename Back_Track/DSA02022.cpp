#include<bits/stdc++.h>
using namespace std;

int a[9];
void out();
int cnt=0;

void Try(int i){
    for(int j = 0 ; j <= 2 ; j+=2){
        a[i] = j;
        if(i == 8) out();
        else Try(i+1);
    }
}

bool check(){
    int l = 1, r = 8;
    while(l <= r){
        if(a[l] != a[r]) return 0;
        l++; r--;
    }
    return 1;
}

void out(){
    if(a[5] == 2 && a[3] == 0 && a[4] == 2 && (a[1]+a[2] != 0)){
        for(int i = 1 ; i <= 8 ; i++){
            if(i == 2 || i == 4) cout << a[i] << "/";
            else cout << a[i];
        }
        cout << endl;
    }
}

int main(){
    Try(1);
    return 0;
}