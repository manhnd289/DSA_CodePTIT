#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n; cin >> n;
    int a[n];
    for(auto &x : a) cin >> x;
    for(int i = 0 ; i < n - 1 ; i++){
        int min = i;
        for(int j = i + 1 ; j < n ; j++){
            if(a[min] > a[j]) min = j;
        }
        swap(a[min],a[i]);
        cout << "Buoc " << i + 1 << ": ";
        for(auto x : a) cout << x << " ";
        cout << endl << endl;
    }
    return 0;
}
