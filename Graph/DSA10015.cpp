#include<bits/stdc++.h>
using namespace std;

struct edge{
    int w,u,v;
};

struct cmp{
    bool operator() (edge a, edge b) {return a.w > b.w;}
};

int v,e,x,y,w,d;
priority_queue<edge , vector<edge> , cmp > canh;
int parent[2003];
int size[2003];
vector<edge> mst;

void init(){
    while(!canh.empty()) canh.pop();
    mst.clear();
    cin >> v >> e;
    for(int i = 0 ; i < e ; i++){
        cin >> x >> y >> w;
        canh.push({w,x,y});
    }
    d = 0;
    for(int i = 0 ; i <= v ; i++){
        parent[i] = i;
        size[i] = 1;
    }
}

int find(int v){
    if(v == parent[v]) return v;
    return parent[v] = find(parent[v]);
}

bool Union(int a, int b){
    a = find(a); b = find(b);
    if(a == b) return 0;
    if(size[a] < size[b]) swap(a,b);
    parent[b] = a;
    size[a] += size[b];
    return 1;
}

void kruskal(){
    while(!canh.empty()){
        if(mst.size() == v-1) break;
        edge top = canh.top(); canh.pop();
        if(Union(top.u,top.v)){
            mst.push_back(top);
            d += top.w;
        }
    }
    cout << d << endl;
}

int main(){
    int t; cin >> t;
    while(t--){
        init();
        kruskal();
    }
}