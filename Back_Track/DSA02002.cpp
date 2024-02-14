#include<bits/stdc++.h>
using namespace std;

int n;
int a[100];
vector<vector<int>> v;

void solve(int n){
    if(n > 1){
        vector<int> v2;
        for(int i = 1 ; i < n ; i++){
            a[i] = a[i] + a[i+1];
            v2.push_back(a[i]);
        }
        v.push_back(v2);
        solve(n-1);
    }
}

void out(){
    for(int i = v.size() - 1 ; i >= 0 ; i--){
        cout << "[";
        for(int j = 0 ; j < v[i].size()-1 ; j++){
            cout << v[i][j] << " ";
        }
        cout << v[i][v[i].size()-1] << "]";
        cout << " ";
    }
    
}

int main(){
    int t; cin >> t;
    while(t--){
        cin >> n;
        vector<int> v1;
        for(int i = 1 ; i <= n ; i++){
            cin >> a[i];
            v1.push_back(a[i]);
        }
        v.push_back(v1);
        solve(n);
        out();
        cout << endl;
        v.clear();
    }
    return 0;
}
