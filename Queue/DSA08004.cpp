#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    int t; cin >> t;
    while(t--){
        int k; cin >> k;
        string s; cin >> s;

        // Đếm số lần xuất hiện từng phần tử
        map<char,int> mp;
        for(char &c : s) mp[c]++;

        // Đẩy cặp ký tự và số lần xuất hiện và sắp xếp theo số lần xuất hiện giảm dần
        priority_queue<pair<int,char>> pq;
        for(auto &x : mp) pq.push({x.second,x.first});

        // Xóa đi 1 lần xuất hiện của ký tự ở top và push vào lại.
        while(k--){
            auto x = pq.top(); pq.pop();
            char a = x.second;
            int b = x.first;
            pq.push({b-1,a});
        }

        // Tìm kết quả
        ll res = 0;
        while(!pq.empty()){
            auto x = pq.top(); pq.pop();
            res += (ll)pow(x.first,2);
        }
        cout << res << endl;
    }
}

// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long

// int main(){
// 	int t; cin >> t;
// 	while(t--){
// 		int n; string s;
// 		cin >> n >> s;

// 		// Đếm số lần xuất hiện
// 		ll a[2003] = {0};
// 		for(char c : s) a[c]++;

// 		// Đẩy phần tử xuất hiện vào pq
// 		priority_queue<ll> pq;
// 		for(char c = 'A' ; c <= 'Z' ; c++){
// 			if(a[c]) pq.push(a[c]);
// 		}

// 		// Giảm n đi 1 thì giảm số lần xuất hiện ở top đi 1
// 		while(!pq.empty() && n--){
// 			ll top = pq.top(); pq.pop();
// 			top--;
// 			pq.push(top);
// 		}
// 		ll res = 0;
// 		while(!pq.empty()){
// 			res += (ll)pow(pq.top(),2); pq.pop();
// 		}
// 		cout << res << endl;
// 	}
// }