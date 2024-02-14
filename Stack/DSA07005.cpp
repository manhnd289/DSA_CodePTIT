#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;
    scanf("\n");
    string s;
    while(t--){
        cin >> s;
        stack<int> st;
        for(int i = 0 ; i < s.size() ; i++){
            // Lưu vị trí (
            if(s[i] == '(') st.push(i);
            // Gặp ) thì xét
            else if(s[i] == ')'){
                if(st.size() > 0){    
                    int top = st.top(); st.pop();
                    if(top == 0) continue;
                    else if(s[top-1] == '+') continue;
                    else if(s[top-1] == '-'){
                        for(int j = top ; j <= i ; j++){
                            if(s[j] == '+') s[j] = '-';
                            else if(s[j] == '-') s[j] = '+';
                        }
                    }
                }
            }
        }
        for(int i = 0 ; i < s.size() ; i++){
            if(s[i] != '(' && s[i] != ')') cout << s[i];
        }
        cout << endl;
    }
}