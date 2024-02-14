#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;
    scanf("\n");
    while(t--){
        string s; cin >> s;
        stack<char> st;
        int cnt = 0;
        for(int i = 0 ; i < s.size() ; i++){
            if(s[i] == '(') st.push(s[i]);
            else{
                if(st.empty()){
                    st.push('(');
                    //Push vao để sửa
                    //Nếu sửa được thì chỉ tính 1 lần ở cnt
                    // Còn không sửa được thì là tính ở st.size()/2
                    cnt++;
                    //Lưu số ngoặc bị sai và phải push '(' coi như sửa luôn và tìm vào để về sau tìm '(' sửa nữa
                }else st.pop();
            }
        }
        cout << cnt + st.size()/2 << endl;
    }
}

// #include<bits/stdc++.h>
// using namespace std;

// int main(){
// 	string s;
// 	int t; cin >> t;
// 	while(t--){
// 		stack<char> st;
// 		cin >> s;
// 		for(char c : s){
// 			// Nếu là ( hoặc ) mà trong stack rỗng thì push vào
//  			if(c == '(' || (c == ')' && st.empty())) st.push(c);
// 			else if(c == ')')
// 			{
// 				//Pop cặp ngoặc đúng đi
// 				if(!st.empty() && st.top() == '(') st.pop();
// 				//Đây là ) bị sai
// 				else st.push(c);
// 			}
// 		}
// 		// Bây giờ trong stack chỉ còn ngoặc sai
// 		int d1 = 0,d2 = 0;
// 		while(!st.empty()){
// 			if(st.top() == '(') d1++;
// 			else d2++;
// 			st.pop();
// 		}
// 		int res = d1/2 + d2/2 + d1%2 + d2%2;
// 		// Đổi chiều 1 nửa ) sai để khớp với nửa còn lại, tương tự với (
// 		// Sửa thêm ngoặc bị lẻ ra của cả 2 cái thì được cặp đúng. Không có trường hợp lẻ ra duy nhất 1 loại do nhập vào số ngoặc là chẵn
// 		cout << res << endl;
// 	}
// }