#include<bits/stdc++.h>
using namespace std;
#define ll long long

// 2 so gan nhau se co tong nho nhat

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int tmp;
        vector<int> v;
        for(int i = 1 ; i <= n ; i++){
            cin >> tmp;
            if(tmp != 0) v.push_back(tmp);
        }
        sort(v.begin(),v.end());
        ll tmp1 = 0;
        ll tmp2 = 0;
        for(int i = 0 ; i < v.size() ; i++){
            if(i%2==0) tmp1 = tmp1*10+v[i];
            else tmp2 = tmp2*10+v[i];
        }
        ll res = tmp1 + tmp2;
        cout << res << endl;
        v.clear();
    }
    return 0;
}