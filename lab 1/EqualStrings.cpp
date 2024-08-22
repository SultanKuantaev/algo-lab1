#include <bits/stdc++.h>

int main(){
    std::stack<char> s1;
    std::stack<char> s2;
    std::string s11, s22;
    std::cin >> s11 >> s22;

    
    for(int i = 0; i < s11.length(); i++){
        if(s11[i] == '#'){
            if(!s1.empty()) s1.pop();  
        }else{
            s1.push(s11[i]);
        }
    }

    
    for(int i = 0; i < s22.length(); i++){
        if(s22[i] == '#'){
            if(!s2.empty()) s2.pop();  
        }else{
            s2.push(s22[i]);
        }
    }

    
    bool areEqual = true;
    while(!s1.empty() && !s2.empty()){
        if(s1.top() != s2.top()){
            areEqual = false;
            break;
        }
        s1.pop();
        s2.pop();
    }

    
    if(!s1.empty() || !s2.empty()){
        areEqual = false;
    }

    if(areEqual){
        std::cout << "Yes" << std::endl;
    } else {
        std::cout << "No" << std::endl;
    }

    return 0;
}
