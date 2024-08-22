/*2 3 5 7 11 13 17
  1 2 3 4  5 6  7
  3 5 11 17 */
#include <bits/stdc++.h>

int main(){
    int n;
    std::cin >> n;
    std::cout << nthsuperprime(n);
}
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
int nthsuperprime(int n){
    int prime_index = 1;
    int count = 0;
    while(true){
        int prime = nthprime(prime_index);
        if(isprime(prime_index)){
            count++;
            if(count == n){
                return prime;
            }
        }
        prime_index++;
    }
}