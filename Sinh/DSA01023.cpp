#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int n,k; cin >> n >> k;
        int a[k+1];
        int b[k+1];
        for(int i = 1 ; i <= k ; i++) cin >> b[i];
        for(int i = 1 ; i <= k ; i++) a[i] = i;
        vector<vector<int>> v;
        while(1){
            vector<int> tmp(a+1,a+k+1);
            v.push_back(tmp);
            bool ok = 1;
            for(int i = 0 ; i < tmp.size() ; i++) if(tmp[i] != b[i+1]) ok = 0;
            if(ok){
                cout << v.size(); break;
            }
            int i = k;
            while(a[i] == n-k+i && i > 0) i--;
            if(i == 0) break;
            else{
                a[i]++;
                for(int j = i+1 ; j <= k ; j++) a[j] = a[j-1] + 1;
            }
        }
        cout << endl;
    }
}