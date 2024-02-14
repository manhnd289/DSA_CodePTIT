#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int n,k; cin >> n >> k;
        int a[k+1];
        int cnt[n+1] = {0};
        for(int i = 1 ; i <= k ; i++){
            cin >> a[i]; cnt[a[i]]++;
        }
        int i = k;
        while(a[i] == n-k+i && i > 0) i--;
        if(i == 0) cout << k;
        else{
            int res = 0;
            a[i]++;
            for(int j = i+1 ; j <= k ; j++) a[j] = a[j-1] + 1;
            for(int j = 1 ; j <= k ; j++){
                cnt[a[j]]++; 
                if(cnt[a[j]] == 1) res++;
            }
            cout << res;
        }
        cout << endl;
    }
}