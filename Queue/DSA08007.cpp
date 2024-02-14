#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        string x; cin >> x;
        queue<string> q;
        int cnt = 0;
        q.push("1");
        while(!q.empty()){
            //Mỗi phần tử xóa đi thì cnt++
            string tmp = q.front(); q.pop();
            cnt++;

            // Kiểm tra rồi mới cho vào queue
            string tmp1 = tmp + "0";
            if(tmp1.size() > x.size() || (tmp1.size() == x.size() && tmp1 > x)) break;
            q.push(tmp1);

            tmp1 = tmp + "1";
            if(tmp1.size() > x.size() || (tmp1.size() == x.size() && tmp1 > x)) break;
            q.push(tmp1);
        }
        // Tất cả phần tử trong queue đều là hợp lệ
        // Run 200 để hiểu
        cout << cnt + q.size() << endl;
    }
}