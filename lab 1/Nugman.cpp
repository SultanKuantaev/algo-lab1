#include <bits/stdc++.h>

int main(){
    int n;
    std::cin >> n;
    std::vector<int> results(n , -1);  
    std::vector<int> ages(n);  
    std::stack<int> s; 

    
    for(int i = 0; i < n; i++){
        std::cin >> ages[i];
    }

    
    for(int i = 0; i < n; i++){
        
        while(!s.empty() && ages[s.top()] >= ages[i]){
            s.pop();
        }

        
        if(!s.empty()){
            results[i] = ages[s.top()];
        }

        
        s.push(i);
    }

    
    for(auto item : results){
        std::cout << item << " ";
    }

    return 0;
}
