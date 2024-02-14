#include<bits/stdc++.h>
using namespace std;

bool check(string s){
    stack<int> st;
    for(int i = 0 ; i < s.size() ; i++){
        if(s[i] == ')' && !st.empty() && s[st.top()] == '(') st.pop();
        else if(s[i] == ']' && !st.empty() && s[st.top()] == '[') st.pop();
        else if(s[i] == '}' && !st.empty() && s[st.top()] == '{') st.pop();
        else st.push(i);
    }
    return st.empty();
}

int main(){
    string s;
    int t; cin >> t;
    while(t--){
        cin >> s;
        if(check(s)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}
