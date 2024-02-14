#include<bits/stdc++.h>
using namespace std;

int v,e,x,y;
set<int> adj[2003];
int degreein[2003];
int degreeout[2003];

void init(){
    memset(degreein,0,sizeof(degreein));
    memset(degreeout,0,sizeof(degreeout));
    for(int i = 0 ; i < 2003 ; i++) adj[i].clear();
    cin >> v >> e;
    for(int i = 0 ; i < e ; i++){
        cin >> x >> y;
        degreeout[x]++;
        degreein[y]++;
    }
}

int euler(int u){
    int cnt = 0;
    for(int i = 1 ; i <= v ; i++) if(degreein[i] != degreeout[i]) cnt++;
    if(cnt == 0) return 1;
    return 0;
}

int main(){
    int t; cin >> t;
    while(t--){
        init();
        int a = euler(3);
        cout << a << endl;
    }
}