#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        string s; cin >> s;
        int i = s.size()-1;
        while(s[i] == '0' && i > -1){
            s[i] = '1'; i--;
        }
        if(i == -1) cout << s;
        else{
            s[i] = '0'; cout << s;
        }
        cout << endl;
    }
}