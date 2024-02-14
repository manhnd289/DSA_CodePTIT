#include<bits/stdc++.h>
using namespace std;

int n;

void solve(int n,char nguon, char trungGian , char dich){
    if(n == 1){
        cout << nguon << " -> " << dich << endl;
        cout << "," << endl;
    }
    else{
        solve(n-1,nguon,dich,trungGian);
        cout << "." << endl;
        solve(1,nguon,trungGian,dich);
        cout << ".." << endl;
        solve(n-1,trungGian,nguon,dich);
        cout << "..." << endl;
    }
}

int main(){
    cin >> n;
    solve(n,'A','B','C');
    return 0;
}