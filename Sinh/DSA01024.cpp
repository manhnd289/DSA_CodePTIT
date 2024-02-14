#include<bits/stdc++.h>
using namespace std;

vector<string> v;
int n,k; 
int a[203];

void out(){
    for(int i = 1 ; i <= k ; i++){
        cout << v[a[i] -1] << " ";
    }
    cout << endl;
}

void Try(int i){
    for(int j = a[i-1] + 1 ; j <= v.size() ; j++){
        a[i] = j;
        if(i == k) out();
        else Try(i+1);
    }
}


int main(){
    cin >> n >> k;
    string s;
    while(n--){
        cin >> s;
        if(find(v.begin(), v.end() , s) == v.end()) v.push_back(s);
    }
    sort(v.begin(),v.end());
    a[0] = 0;
    Try(1);
}