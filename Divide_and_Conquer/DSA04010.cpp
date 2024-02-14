#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int res = -1e9;
        int sum = 0;
        int n; cin >> n;
        int a[n];
        for(int i = 0 ; i < n ; i++) cin >> a[i];
        for(int i = 0 ; i < n ; i++){
            sum += a[i];
            res = max(res,sum);
            if(sum < 0) sum = 0;
        }
        cout << res << endl;
    }
    return 0;
}