// Danh sach ke sang ma tran ke
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    scanf("\n");
    int a[n+1][n+1];
    memset(a,0,sizeof(a));
    string s,num;
    // for(int i = 1 ; i <= n ; i++){
    //     getline(cin,s);
    //     for(int j = 0 ; j < s.size() ; j+=2){
    //         a[i][s[j]-'0'] = 1;
    //     }
    // }
    for(int i = 1 ; i <= n ; i++){
        getline(cin,s);
        stringstream ss(s);
        while(ss >> num){
            a[i][stoi(num)] = 1;
        }
    }
    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= n ; j++){
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}