#include<bits/stdc++.h>
using namespace std;

string s;
int l;
int a[100],check[100]; 
void out();

void Try(int i){
    for(int j = 1 ; j <= l ; j++){
        if(!check[j]){
            check[j] = 1;
            a[i] = j;
            if(i == l) out();
            else Try(i + 1);
            check[j] = 0;
        }
    }
}

void out(){
    for(int i = 1 ; i <= l ; i++){
        cout << s[a[i]-1];
    }
    cout << " ";
}

int main(){
    int t; cin >> t;
    while(t--){
        cin >> s;
        sort(s.begin(), s.end());
        l = s.size();
        Try(1);
        cout << endl;
        memset(a,0,sizeof(a));
    }
    return 0;
}