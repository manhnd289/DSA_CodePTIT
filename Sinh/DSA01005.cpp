#include<bits/stdc++.h>
using namespace std;

int n;
bool check[10];
int a[203];

void Try(int i){
    for(int j = 1 ; j <= n ; j++){
        if(!check[j]){
            check[j] = 1;
            a[i] = j;
            if(i == n){
                for(int i = 1 ; i <= n ; i++) cout << a[i];
                cout << " ";
            }
            else Try(i + 1);
            check[j] = 0;
        }
    }
}

int main(){
    int t; cin >> t;
    while(t--){
        cin >> n;
        Try(1);
        cout << endl;
    }
}

// #include<bits/stdc++.h>
// using namespace std;

// int main(){
//     int t; cin >> t;
//     while(t--){
//         int n; cin >> n;
//         int a[n+1];
//         for(int i = 1 ; i <= n ; i++) a[i] = i;
//         while(1){
//             for(int i = 1 ; i <= n ; i++) cout << a[i];
//             cout << " ";
//             int i = n-1;
//             while(a[i] > a[i+1] && i > 0) i--;
//             if(i == 0) break;
//             else{
//                 int k = n;
//                 while(a[k] < a[i]) k--;
//                 swap(a[k],a[i]);
//                 int l = i+1, r = n;
//                 while(l < r){
//                     swap(a[l],a[r]);
//                     l++; r--;
//                 }
//             }
//         }
//         cout << endl;
//     }
// }