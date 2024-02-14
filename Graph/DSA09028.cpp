#include<bits/stdc++.h>
using namespace std;

int v,e,x,y,m;
int a[2003][2003];
vector<pair<int,int>> vt;
int color[2003];
int deg[2003];   

// Sắp xếp đỉnh có bậc giảm dần
// Chọn đỉnh bậc cao nhất tô màu và tô cùng màu đó với đỉnh không liên thuộc mà chưa được tô

void init(){
    memset(deg,0,sizeof(deg));
    memset(color,0,sizeof(color));
    memset(a,0,sizeof(a));
    vt.clear();
    cin >> v >> e >> m;
    for(int i = 1 ; i <= e ; i++){
        cin >> x >> y;
        a[x][y] = a[y][x] = 1;
        deg[x]++; deg[y]++;
    }
    for(int i = 1 ; i <= v ; i++) vt.push_back({i,deg[i]});
    sort(vt.begin(),vt.end(), [](pair<int,int> a, pair<int,int> b) -> bool {
        return a.second > b.second;
    });
}

bool check(){
    int cnt = 0;
    for(auto x : vt){
        int tmp = x.first;
        if(color[tmp] == 0){
            cnt++;
            color[tmp] = cnt;
            for(int i = 1 ; i <= v ; i++){
                if(color[i] == 0 && a[i][tmp] == 0) color[i] = cnt;
            }
        }
    }
    return cnt <= m;
}

int main(){
    int t; cin >> t;
    while(t--){
        init();
        cout << (check() ? "YES" : "NO") << endl;
        for(int i =1 ; i <= v ; i++) cout << color[i] << " ";
    }
}