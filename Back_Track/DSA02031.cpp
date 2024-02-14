// #include<bits/stdc++.h>
// using namespace std;

// char c;
// int n;
// char s[1000];
// int check[200];

// bool checkVowel(char c){
//     return (c=='E' || c=='A');
// }

// bool check1(){
//     for(int i = 2 ; i < n ; i++){
//         if(checkVowel(s[i]) && !checkVowel(s[i-1]) && !checkVowel(s[i+1])) return 0;
//     }
//     return 1;
// }

// void Try(int i){
//     for(char j = 'A' ; j <= c ; j++){
//         if(!check[j]){
//             check[j] = 1;
//             s[i] = j;
//             if(i == n && check1()){
//                 for(int i = 1 ; i <= n ; i++) cout << s[i];
//                 cout << endl;
//             }
//             else Try(i+1);
//             check[j] = 0;
//         }
//     }
// }

// int main(){
//     cin >> c;
//     n = c-'A'+1;
//     Try(1);
//     return 0;
// }

#include<bits/stdc++.h>
using namespace std;

char c;
string s;

bool checkVowel(char c){
    return c=='E' || c=='A';
}

bool check(){
    for(int i = 1 ; i < s.size()-1 ; i++){
        if(checkVowel(s[i]) && !checkVowel(s[i-1]) && !checkVowel(s[i+1])) return 0;
    }
    return 1;
}

int main(){
    cin >> c;
    for(char i = 'A' ; i <= c ; i++) s+=i;
    do{
        if(check()) cout << s << endl;
    }while(next_permutation(s.begin(),s.end()));
}