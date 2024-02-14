#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int a[n+1];
        for(int i = 1 ; i <= n ; i++) cin >> a[i];
        int j = n-1;
        // Tìm từ phải sang trái vị trí mà phần tử đó nhỏ hơn phần tử bên phải vì cấu hình cuối cùng phải là tăng dần từ phải qua trái
        while(a[j] > a[j+1] && j > 0) j--;
        if(j == 0){
            for(int k = 1 ; k <= n ; k++) cout << k << " ";
        }else{
            int k = n;
            // Tìm phần tử đầu tiên lớn hơn phần tử tìm được
            while(a[k] < a[j]) k--;
            // Đổi chỗ
            swap(a[k],a[j]);
            int l = j + 1, r = n;
            // Lật ngược từ j+1 đến n
            while(l < r){
                swap(a[l],a[r]); l++; r--;
            }
            for(int m = 1 ; m <= n ; m++) cout << a[m] << " ";
        }
        cout << endl;
    }
}