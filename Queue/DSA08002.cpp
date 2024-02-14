#include<bits/stdc++.h>
using namespace std;

int main(){
    queue<int> q;
    int t; cin >> t;
    while(t--){
        scanf("\n");
        string s; cin >> s;
        if(s == "PUSH"){
            int x; cin >> x; q.push(x);
        }else if(s == "PRINTFRONT"){
            if(!q.empty()) cout << q.front() << endl;
            else cout << "NONE" << endl;
        }
        else if(s == "POP" && !q.empty()) q.pop();
    }
}