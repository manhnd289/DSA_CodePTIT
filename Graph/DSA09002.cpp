#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    scanf("\n");
    vector<pair<int,int>> edge;
    string s,num;
    for(int i = 1 ; i <= n ; i++){
        getline(cin,s);
        stringstream ss(s);
        while(ss >> num){
            if(stoi(num) > i){
                edge.push_back({i,stoi(num)});
            }
        }
    }
    for(auto x : edge){
        cout << x.first << " " << x.second << endl;
    }
}