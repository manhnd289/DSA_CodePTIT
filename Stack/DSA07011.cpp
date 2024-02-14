#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    int t; cin >> t;
    while(t--){
        stack<string> st;
        cin >> s;
        for(char c : s){
            if(isalpha(c)) st.push(string(1,c));
            else{
                string fi = st.top(); st.pop();
                string se = st.top(); st.pop();
                string tmp = c + se + fi;
                st.push(tmp);
            }
        }
        cout << st.top() << endl;
    }
}