#include<bits/stdc++.h>
using namespace std;

int main(){
	int t; cin >> t;
	while(t--){
		vector<vector<int>> v;
		int n; cin >> n;
		int a[n+1];
		for(int i = 1 ; i <= n ; i++) a[i] = n-i+1;
		do{
			vector<int> tmp(a+1, a+n+1);
			v.push_back(tmp);
		}while(prev_permutation(a+1,a+n+1));
		for(auto i : v){
			for(auto j : i) cout << j;
			cout << " ";
		}
		cout << endl;
	}
}



/*
#include<bits/stdc++.h>
using namespace std;

int n; 
int a[203];
vector<vector<int>> v;
bool check[10];

void Try(int i){
    for(int j = 1 ; j <= n ; j++){
        if(!check[j]){
            check[j] = 1;
            a[i] = j;
            if(i == n){
                vector<int> tmp(a+1,a+n+1);
                v.push_back(tmp);
            }
            else Try(i+1);
            check[j] = 0;
        }
    }
}

int main(){
    int t; cin >> t;
    while(t--){
        memset(check,0,sizeof(check));
        v.clear();
        cin >> n;
        Try(1);
        for(int i = v.size()-1 ; i >= 0 ; i--){
            for(int j = 0 ; j < v[i].size() ; j++) cout << v[i][j];
            cout << " ";
        }
        cout << endl;
    }
}
*/



/*
#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int a[n+1];
        for(int i = 1 ; i <= n ; i++) a[i] = i;
        vector<vector<int>> v;
        while(1){
            vector<int> tmp(a+1,a+n+1);
            v.push_back(tmp);
            int i = n-1;
            while(a[i] > a[i+1] && i > 0) i--;
            if(i == 0) break;
            else{
                int k = n;
                while(a[k] < a[i]) k--;
                swap(a[i],a[k]);
                int l = i+1, r = n;
                while(l < r){
                    swap(a[l],a[r]); l++; r--;
                }
            }
        }
        for(int i1 = v.size()-1 ; i1 >= 0 ; i1--){
            for(int j = 0 ; j < v[i1].size() ; j++) cout << v[i1][j];
            cout << " ";
        }
        cout << endl;
    }
}
*/