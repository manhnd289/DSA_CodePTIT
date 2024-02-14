#include<bits/stdc++.h>
using namespace std;
#define ll long long

//Day con do dai k sau khi sort o dau hoac cuoi deu duoc

int main(){
    int t; cin >> t;
    while(t--){
        int n,k; cin >> n >> k;
        int a[n];
        for(int i = 0 ; i < n ; i++) cin >> a[i];
        sort(a,a+n);
        int j = 0;
        ll tmp1 = 0;
        ll tmp2 = 0;
        while(j < n){
            if(j < k) tmp1 += a[j];
            else tmp2 += a[j];
            j++;
        }
        ll res = abs(tmp1-tmp2);
        j = 0;
        tmp1 = tmp2 = 0;
        while(j < n){
            if(j < n-k) tmp1 += a[j];
            else tmp2 += a[j];
            j++;
        }
        res = max(res,abs(tmp2-tmp1));
        cout << res << endl;
    }
    return 0;
}