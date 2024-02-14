#include<bits/stdc++.h>
using namespace std;

int main(){
	int t; cin >> t;
	while(t--){
        int n,S;
		cin >> n >> S;
		int a[n];
		for(int i = 0 ; i < n ; i++) cin >> a[i];
		vector<bool> dp(S+1,0);
		dp[0] = 1;
		for(int i = 0 ; i < n ; i++){
			for(int j = S ; j >= a[i] ; j--){
				if(dp[j-a[i]]) dp[j] = 1;
			}
		}
		if(dp[S]) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
}
