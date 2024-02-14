#include<bits/stdc++.h>
using namespace std;

int n,k;
int a[100]; // Sinh nhị phân
int b[100]; // Nhập dữ liệu
int cnt = 0;

void Try(int i){
	for(int j = 0 ; j <= 1 ; j++){
		a[i] = j;
		if(i == n){
			int sum = 0;
			for(int k = 1 ; k <= n ; k++){
				sum += a[k] * b[k];
			}
			if(sum == k){
				for(int k = 1 ; k <= n ; k++){
					if(a[k]) cout << b[k] << " ";
				}
				cout << endl; 
				cnt++;
			}
		}
		else Try(i+1);
	}
}

int main(){
	cin >> n >> k;
	for(int i = 1 ; i <= n ; i++) cin >> b[i];
	Try(1);
	cout << cnt;
	// Số dãy con tổng = k
}
