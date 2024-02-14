#include<bits/stdc++.h>
using namespace std;

int n;
int a[100];

int main(){
    int t; cin >> t;
    while(t--){
        cin >> n;
        for(int i = 0 ; i < n ; i++) a[i] = i+1;
        do{
            bool check = 1;
            for(int i = 1 ; i < n ; i++) if(abs(a[i] - a[i-1]) == 1) check = 0;
            if(check){
                for(int i = 0 ; i < n ; i++) cout << a[i];
                cout << endl;
            }
        }while(next_permutation(a,a+n));
    }
}