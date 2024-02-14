#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    int t; cin >> t;
    while(t--){
        cin >> s;
        stack<string> st;
        for(int i = s.size()-1 ; i>=0 ; i--){
            if(isalpha(s[i])) st.push(string(1,s[i]));
            else{
                string fi = st.top(); st.pop();
                string se = st.top(); st.pop();
                string tmp = "(" + fi + s[i] + se + ")";
                st.push(tmp);
            }
        }
        cout << st.top() << endl;
    }
}