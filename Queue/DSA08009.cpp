#include<bits/stdc++.h>
using namespace std;

int BFS(int a,int b){
    queue<pair<int,int>> q;
    map<int,bool> mp; // Check xem phần tử đó đã xuất hiện hay chưa xuất hiện rồi thì không được push vào
    q.push({a,0});
    while(!q.empty()){
        auto tmp = q.front(); q.pop();
        if(tmp.first == b) return tmp.second; // Tìm ra rồi thì xuất luôn số bước 
        if(tmp.first*2 == b || tmp.first-1 == b) return tmp.second+1; // Chỉ còn 1 bước nữa là tìm được
        // Phần tử đó còn nhỏ hơn b và chưa xuất hiện
        if(tmp.first < b && mp[tmp.first*2] == 0){
            q.push({tmp.first*2,tmp.second+1});
            mp[tmp.first*2] = 1;
        }
        // Phần tử đó còn dương và chưa xuất hiện để đi được đến b
        if(tmp.first-1 > 0 && mp[tmp.first-1] == 0){
            q.push({tmp.first-1,tmp.second+1});
            mp[tmp.first-1] = 1;
        }
    }
    return -1;
}

int main(){
    int T; cin >> T;
    while(T--){
        int s,t; cin >> s >> t;
        cout << BFS(s,t) << endl;
    }
}