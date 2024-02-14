#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
	int t; cin >> t;
	while(t--){
		string s; cin >> s;
		stack<ll> st;
		for(char c : s){
            // Nếu là số thì thêm vào đã
			if(isdigit(c)) st.push(c-'0');
			else{
                // Lấy ra 2 số ở đầu và tính toán khi gặp toán tử
				ll a = st.top(); st.pop();
				ll b = st.top(); st.pop();
				ll tmp;
				if(c == '+') tmp = b+a;
				else if(c == '-') tmp = b-a;
				else if(c == '*') tmp = b*a;
				else if(c == '/') tmp = b/a;
                // Tính toán xong lại cho vào lại stack để làm dữ liệu cho phép tính sau
				st.push(tmp);
			}
		}
        // Kết quả cuối cùng ở đỉnh stack
		cout << st.top() << endl;
	}
}