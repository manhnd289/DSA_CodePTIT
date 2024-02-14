#include<bits/stdc++.h>
using namespace std;

int main(){
	int t; cin >> t;
	while(t--){
		string s; cin >> s;
		int n = s.size();
		bool F[n][n];
		memset(F,0,sizeof(F));
		for(int i = 0 ; i < n ; i++) F[i][i] = 1;
		int res = 1;
		for(int len = 2 ; len <= n ; len++){
			for(int i = 0 ; i <= n-len ; i++){
				int j = i+len-1;
				if(len == 2 && s[i] == s[j]) F[i][j] = 1;
				else F[i][j] = F[i+1][j-1] && (s[i] == s[j]);
				if(F[i][j]) res = max(res,len);
			}
		}
		cout << res << endl;
	}
}
