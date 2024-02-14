#include<bits/stdc++.h>
using namespace std;

int main(){
	int t; cin >> t;
	scanf("\n");
	string s,tmp;
	while(t--){
		stack<string> st;
		getline(cin,s);
		stringstream ss(s);
		while(ss >> tmp){
			st.push(tmp);
		}
		while(!st.empty()){
			cout << st.top() << " "; st.pop();
		}
		cout << endl;
	}
}