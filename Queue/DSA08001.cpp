#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        queue<int> q;
        int tv; cin >> tv;
        while(tv--){
            int x; cin >> x;
            if(x == 1) cout << q.size() << endl;
            else if(x == 2) cout << (q.empty() ? "YES" : "NO") << endl;
            else if(x == 3){
                int tmp; cin >> tmp; q.push(tmp);
            }
            else if(x == 4 && !q.empty()) q.pop();
            else if(x == 5) cout << (!q.empty() ? q.front() : -1) << endl;
            else if(x == 6) cout << (!q.empty() ? q.back() : -1) << endl;
        }
    }
}