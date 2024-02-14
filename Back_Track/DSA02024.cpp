#include<bits/stdc++.h>
using namespace std;

int n,a[100];
vector<string> v;

void init(){
    cin >> n;
    for(int i = 1 ; i <= n ; i++) cin >> a[i];
}

void Try(int i, string s, int cnt){
    if(cnt >= n) return;
    for(int j = i + 1 ; j <= n ; j++){
        if(a[i] < a[j]){
            if(cnt >= 1) v.push_back(s + to_string(a[j]) + " ");
            Try(j, s + to_string(a[j]) + " ", cnt+1);
        }
    }
}

int main(){
    init();
    Try(0,"",0);
    sort(v.begin(),v.end());
    for(auto x : v){
        cout << x << endl;
    }
    return  0;
}