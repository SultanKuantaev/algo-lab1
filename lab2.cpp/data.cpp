#include<bits/stdc++.h>

int main(){
    int n;
    std::cin >> n;
    std::map<std::string , int> data;
    for(int i = 0; i < n; i++){
        std::string name;
        std::cin >> name;
        data[name]++;
    }
    std::cout << "All in all : " << data.size() << std::endl;
    std::cout << "Students:" << std::endl;
    for(auto it = data.rbegin(); it != data.rend(); ++it){
        std::cout << it -> first << std::endl;
    }
}
