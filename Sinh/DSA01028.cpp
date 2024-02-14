#include<bits/stdc++.h>
using namespace std;

int n,k;
set<int> s;
vector<int> v;
int a[15];

void out(){
    for(int i = 1 ; i <= k ; i++){
        cout << v[a[i]] << " ";
    }
    cout << endl;
}

void Try(int i){
    for(int j = a[i-1] + 1 ; j < v.size() - k + i ; j++){
        a[i] = j;
        if(i == k) out();
        else Try(i+1);
    }
}

int main(){
    cin >> n >> k;
    for(int i = 1 ; i <= n ; i++){
        int x; cin >> x;
        s.insert(x);
    }
    v.push_back(0);
    for(auto it : s) v.push_back(it);
    a[0] = 0;
    Try(1);
}