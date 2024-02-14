#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int res;
        int n; cin >> n;
        int a[n+1];
        int b[n+1];
        for(int i = 1 ; i <= n ; i++) a[i] = i;
        for(int i = 1 ; i <= n ; i++) cin >> b[i];
        vector<vector<int>> v;
        do{
            vector<int> tmp(a+1,a+n+1);
            v.push_back(tmp);
            bool ok = 1;
            for(int i = 0 ; i < tmp.size() ; i++){
                if(tmp[i] != b[i+1]) ok = 0;
            }
            if(ok){
                res = v.size(); break;
            }
        }while(next_permutation(a+1,a+n+1));
        cout << res << endl;
    }
}