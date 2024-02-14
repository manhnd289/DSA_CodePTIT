#include<bits/stdc++.h>
using namespace std;

struct data{
    int si,fi;
};

data m[1005];

bool cmp(data a, data b){
    return a.fi < b.fi; // sort theo tgian ket thuc 
}

int main(){
    int t; cin >> t;
    while(t--){
        int cnt = 1;// It nhat 1 cong viec
        int n; cin >> n;
        for(int i = 0 ; i < n ; i++) cin >> m[i].si;
        for(int i = 0 ; i < n ; i++) cin >> m[i].fi;
        sort(m,m+n,cmp);
        int i = 0; // Cong viec dang thuc hien
        for(int j = 1 ; j < n ; j++){ // Cong viec tiep theo do
            if(m[j].si >= m[i].fi){
                cnt++; i = j;
            }
        }
        cout << cnt << endl;
    }
    return 0;
}