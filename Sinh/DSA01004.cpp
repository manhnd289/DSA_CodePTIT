#include<bits/stdc++.h>
using namespace std;

int n,k; 
int a[203];

void Try(int i){
    for(int j = a[i-1] + 1 ; j <= n-k+i ; j++){
        a[i] = j;
        if(i == k){
            for(int m = 1 ; m <= k ; m++) cout << a[m];
            cout << " ";
        }
        else Try(i + 1);
    }
}

int main(){
    int t; cin >> t;
    while(t--){
        a[0] = 0;
        cin >> n >> k;
        Try(1);
        cout << endl;
    }
}

// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//     int t; cin >> t;
//     while(t--){
//         int n,k; cin >> n >> k;
//         int a[k+1];
//         for(int i = 1 ; i <= k ; i++) a[i] = i;
//         while(1){
//             for(int i = 1 ; i <= k ; i++) cout  << a[i];
//             cout << " ";
//             int i = k;
//             while(a[i] == n-k+i && i > 0) i--;
//             if(i == 0) break;
//             else{
//                 a[i]++;
//                 for(int j = i+1 ; j <= k ; j++) a[j] = a[j-1] + 1;
//             }
//         }
//         cout << endl;
//     }
// }