#include<bits/stdc++.h>
using namespace std;

string s1,s2;
int F[2003][2003];

int main(){
	int t; cin >> t;
	while(t--){
		memset(F,0,sizeof(F));
		cin >> s1 >> s2;
		int n = s1.size(), m = s2.size();
		for(int i = 0 ; i <= n ; i++){
			for(int j = 0 ; j <= m ; j++){
				if(!i || !j) F[i][j] == 0;
				else{
					if(s1[i-1] == s2[j-1]) F[i][j] = F[i-1][j-1] + 1;
					else F[i][j] = max(F[i-1][j],F[i][j-1]);
				}
			}
		}
		cout << F[n][m] << endl;
	}
}
