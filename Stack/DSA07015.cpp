#include<bits/stdc++.h>
using namespace std;
#define ll long long

int degree(char c){
    if(c == '^') return 5;
    else if(c == '*' || c == '/') return 4;
    else if(c == '+' || c == '-') return 3;
    else return 2; 
}

string InfToPost(string s){
    string res = ""; // Lưu biểu thức hậu tố
    stack<char> st;
    for(char c : s){
        if(isdigit(c)) res += c;
        else if(c == '(') st.push(c);
        else if(c == ')'){
            while(!st.empty() && st.top() != '('){
                res += st.top(); st.pop();
            }
            st.pop();
        }
        else if(c == '+' || c == '-' || c == '*' || c == '/' || c == '^' || c == '%'){
            // Khi gặp toán tử mà sau chuỗi kết quả lại gặp số thì là đã nhập xong toán hạng
            // Thêm '#' vào sau mối toán hạng coi như đã nhập xong 1 toán hạng vào biểu thức hậu tố
            if(isdigit(res[res.size()-1])) res += '#';
            // Còn trước ')' không cần xử lý
            while(!st.empty() && degree(st.top()) >= degree(c)){
                res += st.top(); st.pop();
            }
            st.push(c);
        }
    }
    while(!st.empty() && st.top() != '('){
        res += st.top(); st.pop();
    }
    return res;
}

// Tinhs toán giá trị
ll solve(ll a,ll b, char c){
    if(c == '+') return a+b;
    else if(c == '-') return a-b;
    else if(c == '*') return a*b;
    else if(c == '/') return a/b;
    else if(c == '%') return a%b;
    else if(c == '^'){
        ll tmp = b;
        for(int i = 0 ; i < a-1 ; i++) tmp*=b;
        return tmp;
    }
}

int main(){
    int t; cin >> t;
    while(t--){
        string s; cin >> s;
        s = InfToPost(s);
        cout << s << endl;
        stack<ll> st;
        for(int i = 0 ; i < s.size() ; i++){
            // Nếu đến phần có toán tử thì coi như đã lấy được xong hết toán hạng và đến phần tính toán
            // (Có thể in biểu thức hậu tố để check)
            if(s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' || s[i] == '^' || s[i] == '%')
            {
                ll a = st.top(); st.pop();
                ll b = st.top(); st.pop();
                st.push(solve(b,a,s[i]));
            }
            else // Lấy giá trị 1 toán hạng
            {
                ll tmp = 0;
                while(i < s.size() && isdigit(s[i])){
                    tmp = tmp*10 + (ll)(s[i]-'0');
                    i++;
                }
                // Nếu sau ký tự số là '#' thì là đã tìm xong 1 toán hạng và i++ ở vòng while trên coi như là đã bỏ qua nó rồi
                // Còn không phải '#' thì đã hết toán hạng và phải trả về giá trị i cho vòng for
                if(s[i] != '#') i--; // i ở đây là sau mỗi toán hạng
                st.push(tmp);
                // Push giá trị vừa tính được cho phép tính sau
            }
            // Nếu gặp '#' thì sẽ không làm gì cả và để cho giá trị i của for trôi qua
        }
        cout << st.top() << endl;
    }
}