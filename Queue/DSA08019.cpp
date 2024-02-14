#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve(int n){
    int cnt = 0;
    queue<ll> q;
    stack<ll> st;
    q.push(6);
    q.push(8);
    while(!q.empty()){
        ll tmp = q.front(); q.pop();
        st.push(tmp);
        cnt++;
        if(to_string(tmp).size() == n) continue;
        q.push(tmp*10+6);
        q.push(tmp*10+8);
    }
    cout << cnt << endl;
    while(!st.empty()){
        cout << st.top() << " "; st.pop();
    }
    cout << endl;
}

int main(){
    int n;
    int t; cin >> t;
    while(t--){
        cin >> n;
        solve(n);
    }
}