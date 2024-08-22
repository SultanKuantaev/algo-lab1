#include <bits/stdc++.h>

int main(){
    std::string s;
    std::cin >> s;
    std::stack<char> st;
    for(int i = 0; i < s.length(); i++){
        if(!st.empty() && st.top() == s[i]){
            st.pop();
        }else{
            st.push(s[i]);
        }
    }
    if(st.empty()){
        std::cout << "Yes";
    }else{
        std::cout << "No";
    }

}