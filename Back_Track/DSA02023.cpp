#include<bits/stdc++.h>
using namespace std;

int n,n1,k;
string s;
vector<string> v;
int res[100];
void out();

void init(){
    cin >> n >> k;
    for(int i = 1 ; i <= n ; i++){
        cin >> s;
        if(find(v.begin(),v.end(),s) == v.end()) v.push_back(s);
    }
    res[0] = 0;
    n1 = v.size();
    sort(v.begin(),v.end());
}

void Try(int i){
    for(int j = res[i-1] + 1 ; j <= n1-k+i ; j++)
    {
        res[i] = j;
        if(i == k) out();
        else Try(i + 1);
    }
}

void out(){
    for(int i = 1 ; i <= k ; i++){
        cout << v[res[i] -1] << " ";
    }
    cout << endl;   
}


int main(){
    init();
    Try(1);
    return 0;
}