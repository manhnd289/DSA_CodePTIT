#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    int n;
    stack<int> st;
    int q; cin >> q;
    while(q--){
        cin >> s;
        if(s == "PUSH"){
            cin >> n;
            st.push(n);
        }else if(s == "POP"){
            if(st.empty()) continue;
            st.pop();
        }else if(s == "PRINT"){
            if(st.empty()){
                cout << "NONE" << endl;
                continue;
            }
            cout << st.top() << endl;
        }
    }
}