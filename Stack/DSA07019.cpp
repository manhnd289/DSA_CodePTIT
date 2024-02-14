#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    int t; cin >> t; 
    while(t--){
        ll n; cin >> n;
        ll a[n];
        for(ll &x : a) cin >> x;
        stack<ll> st; // lưu những cột cao dần lên
        ll res = -1;
        ll i = 0;
        while(i < n){
            // stack rỗng hay phần tử đang xét còn đang tăng dần thì push vào rồi chuyển sang phần tử tiếp theo
            if(st.empty() || a[i] >= a[st.top()]){
                st.push(i); ++i;
            }else{
                // Nếu dãy không còn tăng nữa thì coi phần tử giảm đầu tiên sau dãy đó là cận trên và push dần ra
                ll idx = st.top(); st.pop();
                // Nếu stack rỗng thì coi như cột đó có thể loang về tận đầu dãy và i chính là độ rộng
                // Còn nếu không sẽ lấy phần tử sau cái phần tử được pop ra coi như chiều cao hcn và tính toán
                if(st.empty()) res = max(res, i * a[idx]);
                else res = max(res, a[idx] * (i - st.top() - 1));
            }
        }
        // Sau khi duyệt hết phần tử thì quay lại xét xem trong stack còn lại chính là dãy tăng cuối cùng
        while(!st.empty()){
            int idx = st.top(); st.pop();
            if(st.empty()) res = max(res, i * a[idx]);
            else res = max(res, a[idx] * (i - st.top() - 1));
        }
        cout << res << endl;
    }
}