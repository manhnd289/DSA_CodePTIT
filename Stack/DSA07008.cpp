#include<bits/stdc++.h>
using namespace std;

//Trả về độ ưu tiên của toán tử
int degree(char c){
	if(c == '^') return 5;
	else if(c == '*' || c == '/') return 4;
	else if(c == '+' || c == '-') return 3;
	else return 2;
}

string solve(string s){
	string res = ""; // Lưu kết quả
	stack<char> st;
	for(char c : s){
		if(c == '(') st.push(c);
		// Nếu là '(' thì push vào stack đợi thấy ')' để xét 1 biểu thức con
		else if(isalpha(c)) res += c;
		// Nếu là toan hạng thì cho luôn vào chuỗi kết quả
		else if(c == ')'){
			while(!st.empty() && st.top() != '('){
				res += st.top(); st.pop();
			}
			st.pop();
			// Nếu là ')' mà trong stack có toán tử thì cho vào chuỗi kết quả đến khi gặp '('
            // Cuối cùng thì pop '(' đi
		}else if(c == '+' || c == '-' || c == '*' || c == '/' || c == '^'){
			while(!st.empty() && degree(st.top()) >= degree(c)){
				res += st.top(); st.pop();
			}
			st.push(c);
			// Nếu là toán tử mà trong stack cũng có toán tử mà có thứ tự ưu tiên lớn hơn hiện tại thì lấy
            // toán tử có thứ tự ưu tiên lớn hơn đó cho vào stack rồi cho toán tử hiện tại vào stack để đợi.
		}
	}

	// Vét hết toán tử trong stack
	while(!st.empty() && st.top() != '('){
		res += st.top(); st.pop();
	}
	return res;
}

int main(){
	int t; cin >> t;
	scanf("\n");
	while(t--){
		string s; cin >> s;
		s = solve(s);
		cout << s << endl;
	}
}