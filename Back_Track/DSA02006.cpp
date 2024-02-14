#include<bits/stdc++.h>
using namespace std;

int n,k;
int a[100],b[100];
vector< vector<int> > v;

void init(){
    v.clear();
    cin >> n >> k;
    for(int i = 1 ; i <= n ; i++) cin >> b[i];
    sort(b+1,b+n+1);
}

void Try(int i){
    for(int j = 0 ; j <= 1 ; j++){
        a[i] = j;
        if(i == n){
            int sum = 0;
            for(int l = 1 ; l <= n ; l++) if(a[l]) sum+=b[l];
            if(sum == k){
                vector<int> v1;
                for(int l = 1 ; l <= n ; l++) if(a[l]) v1.push_back(b[l]);
                v.push_back(v1);
            }
        }
        else Try(i+1);
    }
}

void out(){
    sort(v.begin(),v.end());
    for(int i = 0 ; i < v.size() ; i++){
        cout << "[";
        for(int j = 0 ; j < v[i].size() - 1 ; j++) cout << v[i][j] << " ";
        cout << v[i][v[i].size() - 1] << "] ";
    }
    cout << endl;
}

int main(){
    int t; cin >> t;
    while(t--){
        init();
        Try(1);
        if(v.size() == 0) cout << "-1" << endl;
        else out();
    }
}