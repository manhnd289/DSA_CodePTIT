#include<bits/stdc++.h>
using namespace std;

int n,k;
set<string> res;
int a[203];

void out(){
    int cnt = 0;
    for(int i = 1 ; i <= n-k+1 ; i++){
        bool check = 1;
        for(int j = i ; j <= i+k-1 ; j++){
            if(!a[j]) check = 0;
        }
        if(check && (!a[i+k] && !a[i-1])){
            cnt++;
        }
    }
    if(cnt == 1){
        bool check2 = 0;
        for(int i = 1 ; i <= n ; i++){
            if(!a[i]){
                check2 = 1; break;
            }
        }
        if(check2){
            string tmp = "";
            for(int i = 1 ; i <= n ; i++){
                if(a[i]) tmp += 'A';
                else tmp += 'B';
            }
            res.insert(tmp);
        }
    }
}

void Try(int i){
    for(int j = 0 ; j <= 1 ; j++){
        a[i] = j;
        if(i == n) out();
        else Try(i+1);
    }
}

int main(){
    cin >> n >> k;
    Try(1);
    cout << res.size() << endl;
    for(auto x : res) cout << x << endl;
}