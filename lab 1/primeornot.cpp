#include <bits/stdc++.h>

std::string isprime(int n) {
    if (n < 2) {
        return "no";
    }
    for (int i = 2; i <= std::sqrt(n); i++) {
        if (n % i == 0) {
            return "no";
        }
    }
    return "yes";
}

int main() {
    int n;
    std::cin >> n;
    std::cout << isprime(n) << std::endl;
}
