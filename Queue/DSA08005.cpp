#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int x; cin >> x;
        queue<string> res;
        queue<string> q;
        q.push("1");
        while(!q.empty()){
            string tmp = q.front();
            res.push(tmp);
            q.pop();
            if(res.size() == x) break;
            q.push(tmp + "0");
            q.push(tmp + "1");
        }
        while(!res.empty()){
            cout << res.front() << " ";
            res.pop();
        }
        cout << endl;
    }
}