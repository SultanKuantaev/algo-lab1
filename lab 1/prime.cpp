#include <bits/stdc++.h>

bool isprime(int n){
    if(n < 2){
        return false;
    }
    for(int i = 2; i <= std::sqrt(n); i++ )
    {
        if(n % i == 0)
        {
            return false;
        }
    }
    return true;
}

int nthprime(int n){
    int incr = 2; 
    int count = 0;
    while(true){
        if(isprime(incr)){
            count++;
            if(count == n){
                return incr;
            }
        }
        incr++;
    }
}

int main(){
    int n;
    std::cin >> n;
    std::cout << nthprime(n);
}
