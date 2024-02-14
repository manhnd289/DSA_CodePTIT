#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        string s; cin >> s;
        stack<char> st;
        for(char c : s){
            if(c == ')' && !st.empty() && st.top() == '(') st.pop();
            else st.push(c);
        }
        cout << s.size() - st.size() << endl;
    }
}