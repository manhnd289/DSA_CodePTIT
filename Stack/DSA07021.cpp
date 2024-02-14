#include<bits/stdc++.h>
using namespace std;

void solve(string s){
    stack<int> st;
    st.push(-1);
    // Coi như đúng từ đầu - phần tử cơ sở
    int res = -1;
    for(int i = 0 ; i < s.size() ; i++){
        if(s[i] == '(') st.push(i);
        else{
            st.pop();
            if(st.empty()) st.push(i);
            // Pop xong mà rỗng thì vị trí đó coi như bắt đầu đúng gần nhất
            // Có nghĩa pop luôn cả -1 đi
            else res = max(res,i-st.top());
            // Cứ xóa được 1 cặp thì lại cập nhật giá trị
            // st.top() lúc này  là trước của bắt đầu đúng
        }
    }
    cout << res << endl;
}

int main(){
    int t; cin >> t;
    string s;
    while(t--){
        cin >> s;
        solve(s);
    }
}