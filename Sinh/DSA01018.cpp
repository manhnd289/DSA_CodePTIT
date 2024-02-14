#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int n,k; cin >> n >> k;
        int a[k+1];
        a[0] = 0; // Nếu gặp cấu hình đầu tiên sẽ chuyển về cấu hình cuối
        for(int i = 1 ; i <= k ; i++) cin >> a[i];  
        int i = k;
        while(i >= 1 && a[i] == a[i-1]+1) i--;
        // Tìm vị trí cuối dãy tăng dần trong tổ hợp đó
        if(i != 0) a[i]--;
        // Nếu thỏa mãn tăng dần hết thì là cấu hình đầu tiên còn không thì giảm 1
        for(int j = i+1 ; j <= k ; j++) a[j] = n-k+j;
        // Từ các vị trí sau đó gán với giá trị max mà nó có thể nhận là n-k+j
        for(int m = 1 ; m <= k ; m++) cout << a[m] << ' ';
        cout << endl;
    }
}

// 1234
// 1235
// 1236
// 1245
// 1246
// 1256
// 1345
// 1346
// 1356
// 1456
// 2345
// 2346
// 2356
// 2456
// 3456