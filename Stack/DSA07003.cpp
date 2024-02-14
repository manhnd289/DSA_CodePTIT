#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;
    scanf("\n");
    while(t--){
        stack<char> st;
        bool check = 1;
        string s; getline(cin,s);
        for(int i = 0 ; i < s.size() ; i++){
            if(s[i] != ')') st.push(s[i]);
            else{
                check = 1;
                while(st.top() != '('){
                    // Nếu trong cặp ngoặc có phép tính mới được coi là không bị thừa
                    if(st.top() == '+' || st.top() == '-' || st.top() == '*' || st.top() == '/')
                        check = 0;
                    st.pop();
                }
                st.pop(); // Pop '(' đi
                if(check) break;
            }
        }
        if(check) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
}