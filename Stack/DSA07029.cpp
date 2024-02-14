#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        string s; cin >> s;
        stack<string> st1;
        stack<int> st2;
        for(int i = 0 ; i < s.size() ; i++){
            if(isdigit(s[i])){
                // Lưu số lần lặp vào stack2
                int num = 0;
                while(i < s.size() && isdigit(s[i])){
                    num = num*10 + (s[i]-'0'); i++;
                }
                i--;
                st2.push(num);
            }else if(s[i] == ']'){
                // Tìm chuỗi cần lặp
                string tmp = "";
                while(st1.top() != "["){
                    tmp = st1.top() + tmp;
                    st1.pop();
                }
                st1.pop(); // Xóa '['
                // Tạo chuỗi đã lặp
                string res = "";
                int cnt = st2.top(); st2.pop();
                while(cnt--) res += tmp;
                st1.push(res);
            }else{
                st1.push(string(1,s[i]));
                // Nếu đây là '(' đầu tiên hoặc trước đó không có số thì số lần lặp là 1
                if(s[i] == '[' && (i == 0 || !isdigit(s[i-1]))) st2.push(1);
            }
        }
        // Trường hợp có 1 chữ ở đầu
        string ans = "";
        while(!st1.empty()){
            ans = st1.top() + ans; st1.pop();
        }
        cout << ans << endl;
    }
}