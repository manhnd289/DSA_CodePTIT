#include<bits/stdc++.h>
using namespace std;
#define ll long long

struct edge{
    ll u,v,w;
};

ll v,e,x,y,w;
vector<edge> E;
ll d[2003];
bool ok;

void init(){
    E.clear();
    cin >> v >> e;
    for(int i = 0 ; i < e ; i++){
        cin >> x >> y >> w;
        edge e{x,y,w};
        E.push_back(e);                                                                                                                                                                 
    }
}

// Sau khi lặp v lần mà đến lần thứ v mà ok = 0 có nghĩa là vẫn có sự thay đổi giá trị -> chu trình âm
// ok check vòng lặp đó có thay đổi hay k
// Mọi vòng lặp ok = 1 ,nếu có thay đổi ok = 0
// Không thay đổi ok = 1 mà không thay đổi thì là không chứa chu trình âm thì thoát luôn
bool bellman_ford1(int s){
    fill(d+1,d+v+1,LONG_LONG_MAX);
    d[s] = 0;
    for(int i = 1 ; i <= v ; i++){
        ok = 1;
        for(auto e : E){
            ll u1 = e.u;
            ll v1 = e.v;
            ll w1 = e.w;
            if(d[u1] != LONG_LONG_MAX && d[v1] > d[u1] + w1){
                d[v1] = d[u1] + w1;
                ok = 0;
            }
        }
        if(ok) return 0;
    }
    return 1;
}

// bool bellman_ford(int s){
//     fill(d+1,d+v+1,LONG_LONG_MAX);
//     d[s] = 0;
//     // Duyệt v-1 lần để tìm khoảng cách min
//     for(int i = 1 ; i < v ; i++){
//         for(auto e : E){
//             ll u1 = e.u; 
//             ll v1 = e.v;
//             ll w1 = e.w;
//             if(d[u1] != LONG_LONG_MAX && d[v1] > d[u1] + w1){
//                 d[v1] = d[u1] + w1;
//             }
//         }
//     }
//     // Đến cuối cùng mà vẫn còn muốn thay đổi giá trị là chứa chu trình âm
//     for(auto e : E){
//         ll u1 = e.u;
//         ll v1 = e.v;
//         ll w1 = e.w;
//         if(d[u1] != LONG_LONG_MAX && d[v1] > d[u1] + w1){
//             return 1;
//         }
//     }
//     return 0;
// }

int main(){
    int t; cin >> t;
    while(t--){
        init();
        bool check = 0;
        // Vì đồ thị có thể k liên thông nên phải tìm hết
        for(int i = 1 ; i <= v ; i++){
            if(bellman_ford1(i)){
                check = 1;
                break;
            }
        }
        cout << check << endl;
    }
    return 0;
}