#include<bits/stdc++.h>
using namespace std;

int n,a[100],b[100];

int main(){
    int t; cin >> t;
    while(t--){
        bool check = 1;
        cin >> n;
        //if(n % 2 == 0) check = 0;
        for(int i = 0 ; i < n ; i++) cin >> a[i];
        for(int i = 0 ; i < n ; i++) b[i] = a[i];
        sort(b,b+n);
        for(int i = 0 ; i < n ; i++){
            if(a[i] != b[i] && a[i] != b[n-i-1]){
                check = 0;
                break;
            }
        }
        if(check) cout << "Yes" << endl;
        else cout << "No" << endl;
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
    }
    return 0;
}