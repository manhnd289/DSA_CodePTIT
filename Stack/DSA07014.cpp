#include<bits/stdc++.h>
using namespace std;
#define ll long long

// Trả về giá trị tính toán
ll solve(ll a, ll b, char c){
	if(c == '+') return a+b;
	else if(c == '-') return a-b;
	else if(c == '*') return a*b;
	else if(c == '/') return a/b;
}

int main(){
	int t; cin >> t;
	while(t--){
		stack<ll> st;
		string s; cin >> s;
		// Duyệt từ toán hạng
		for(int i = s.size()-1 ; i >= 0 ; i--){
            // Gặp toán hạng thì push vào st
			if(isdigit(s[i])) st.push(s[i]-'0');
			else{
				ll a = st.top(); st.pop();
				ll b = st.top(); st.pop();
                // Tính toán giá trị và push lại stack để làm dữ liệu cho phép tính sau
				st.push(solve(a,b,s[i]));
			}
		}
		cout << st.top() << endl;
	}
}