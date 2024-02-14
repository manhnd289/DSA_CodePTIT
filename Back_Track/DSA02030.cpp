#include<bits/stdc++.h>
using namespace std;

char c;
int k;
char m = 'A';
char a[100];

void Try(int i, char m){
    for(char j = m ; j <= c ; j++){
        a[i] = j;
        if(i == k){
            for(int i1 = 1 ; i1 <= k ; i1++) cout << a[i1];
            cout << endl;
        }else Try(i+1,j);
    }
}

int main(){
    cin >> c >> k;
    Try(1,m);
}