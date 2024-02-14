#include<bits/stdc++.h>
using namespace std;

int n;
int a[15];
bool check[20];
vector<vector<int>> v;
int b[15];

void Try(int i){
    for(int j = 1 ; j <= n ; j++){
        if(!check[j]){
            check[j] = 1;
            a[i] = j;
            if(i == n){
                vector<int> tmp(a+1,a+n+1);
                v.push_back(tmp);
            }
            else Try(i+1);
            check[j] = 0;
        }
    }
}

int main(){
    cin >> n;
    for(int i = 1 ; i <= n ; i++){
        cin >> b[i];
    }
    sort(b+1,b+n+1);
    Try(1);
    for(int i = 0 ; i < v.size() ; i++){
        for(int j = 0 ; j < v[i].size() ; j++) cout << b[v[i][j]] << " ";
        cout << endl;
    }
}