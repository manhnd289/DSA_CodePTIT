#include<bits/stdc++.h>
using namespace std;

int main(){
    deque<int> dq;
    int t; cin >> t;
    while(t--){
        scanf("\n");
        string s; cin >> s;
        if(s == "PUSHFRONT"){
            int x; cin >> x; dq.push_front(x);
        }else if(s == "PUSHBACK"){
            int x; cin >> x; dq.push_back(x);
        }
        else if(s == "PRINTFRONT"){
            if(!dq.empty()) cout << dq.front() << endl;
            else cout << "NONE" << endl;
        }else if(s == "PRINTBACK"){
            if(!dq.empty()) cout << dq.back() << endl;
            else cout << "NONE" << endl;
        }else if(s == "POPFRONT" && !dq.empty()) dq.pop_front();
        else if(s == "POPBACK" && !dq.empty()) dq.pop_back();
    }
}