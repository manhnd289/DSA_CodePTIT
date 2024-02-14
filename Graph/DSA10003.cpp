#include<bits/stdc++.h>
using namespace std;

int v,e,x,y;
int parent[2003];
int size[2003];

void make_set(){
    for(int i = 1 ; i <= v ; i++){
        parent[i] = i;
        size[i] = 1;
    }
}

int find(int v){
    if(v == parent[v]) return v;
    return parent[v] = find(parent[v]);
}

// Kiểm tra có cần gộp 2 đỉnh vào 1 tập hợp hay không
bool Union(int a,int b){
    a = find(a); b = find(b);
    if(a == b) return 0;
    // Nếu đã chung cha trong lần Union đầu tiên thì đó là 1 chu trình
    if(size[a] < size[b]) swap(a,b);
    parent[b] = a;
    size[a] += size[b];
    return 1;
}

int main(){
    int t; cin >> t;
    while(t--){
        cin >> v >> e;
        make_set();
        bool check = 0;
        for(int i = 0 ; i < e ; i++){
            cin >> x >> y;
            if(!Union(x,y)) check = 1;
        }
        cout << (check ? "YES" : "NO") << endl;
    }
}