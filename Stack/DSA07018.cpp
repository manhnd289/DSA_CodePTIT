#include<bits/stdc++.h>
using namespace std;

int a[10005];

void solve(string s){
    stringstream ss(s);
    string tmp;
    while(ss >> tmp){
        if(tmp == "+") continue;
        int i = 0;
        while(isdigit(tmp[i])) i++;
        int x = stoi(tmp.substr(0,i));
        while(!isdigit(tmp[i])) i++;
        int y = stoi(tmp.substr(i));
        a[y] += x;
    }
}

int main(){
    int t; cin >> t;
    scanf("\n");
    while(t--){
        memset(a,0,sizeof(a));
        string s1,s2;
        getline(cin,s1);
        getline(cin,s2);
        solve(s1);
        solve(s2);
        for(int i = 10004 ; i >= 0 ; i--){
            if(a[i] != 0 && i != 0) cout << a[i] << "*x^" << i << " + ";
            else if(i == 0 && a[i] != 0) cout << a[i] << "*x^0";
        }
        cout << endl;
    }
}