#include<bits/stdc++.h>
using namespace std;

int n;
int a[2003];

//  n lẻ sinh nhị phân n/2 và thêm 0 hoặc 1 vào giữa rồi in xuôi và in ngược
void out1(){
    for(int i = 0 ; i <= 1 ; i++){
        for(int j = 1 ; j <= n/2 ; j++) cout << a[j] << " ";
        cout << i << " ";
        for(int j = n/2 ; j >= 1 ; j--) cout << a[j] << " ";
        cout << endl;
    }
}

// n chẵn sinh xâu nhị phân n/2 in xuôi rồi in ngược 1 lần nữa
void out2(){
    for(int j = 1 ; j <= n/2 ; j++) cout << a[j] << " ";
    for(int j = n/2 ; j >= 1 ; j--) cout << a[j] << " ";
    cout << endl;
}

void Try(int i){
    for(int j = 0 ; j <= 1 ; j++){
        a[i] = j;
        if(i == n/2){
            if(n % 2) out1();
            else out2();
        }
        else Try(i + 1);
    }
}

int main(){
    cin >> n;
    Try(1);
}