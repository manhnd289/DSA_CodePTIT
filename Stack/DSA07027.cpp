#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    int t; cin >> t;
    while(t--){
        stack<int> st;
        cin >> n;
        int a[n], r[n];
        for(int &x : a) cin >> x;
        for(int i = n-1 ; i >= 0 ; i--){
            while(!st.empty() && st.top() <= a[i]) st.pop();
            if(st.empty()) r[i] = -1;
            else r[i] = st.top();
            st.push(a[i]);
        }
        for(int x : r) cout << x << " ";
        cout << endl;
    }
}