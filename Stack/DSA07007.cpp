#include<bits/stdc++.h>
using namespace std;

// Tìm biểu thức tương đương khi bỏ hết dấu ngoặc
string solve(string s){
    stack<int> st;
    for(int i = 0 ; i < s.size() ; i++){
        // Lưu vị trí '('
        if(s[i] == '(') st.push(i);
        // Gặp ')' thì xét xem trước '(' tương ứng là gì
        else if (s[i] == ')'){
            int top = st.top(); st.pop();
            // Nếu '(' tương ứng là '(' đầu tiên hoặc trước là '+' thì không làm gì 
            if(top == 0 || s[top-1] == '+') continue;
            // Nếu trước '(' tương ứng là '-' thì đổi dấu tất cả toán tử
            else if(s[top-1] == '-'){
                for(int j = i ; j >= top ; j--){
                    if(s[j] == '+') s[j] = '-';
                    else if(s[j] == '-') s[j] = '+';
                }
            }
        }
    }
    // Trả về chuỗi sau khi bỏ ngoặc
    string res = "";
    for(char c : s){
        if(c != '(' && c != ')') res += c;
    }
    return res;
}

int main(){
    int t; cin >> t;
    string p1,p2;
    while(t--){
        cin >> p1 >> p2;
        p1 = solve(p1);
        p2 = solve(p2);
        if(p1 == p2) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}