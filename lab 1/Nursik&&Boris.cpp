#include <bits/stdc++.h>

int main() {
    std::deque<int> Boris;
    std::deque<int> Nursik;

    
    for (int i = 0; i < 5; i++) {
        int c;
        std::cin >> c;
        Boris.push_front(c);
    }

    
    for (int i = 0; i < 5; i++) {
        int c;
        std::cin >> c;
        Nursik.push_front(c);
    }

    int incr = 0;

    while (!Boris.empty() && !Nursik.empty() && incr < 1000000) {
        incr++;
        
        int b_card = Boris.front();
        int n_card = Nursik.front();

        Boris.pop_front();
        Nursik.pop_front();

        
        if ((b_card == 0 && n_card == 9) || (b_card > n_card && !(b_card == 9 && n_card == 0))) {
            Boris.push_back(b_card);
            Boris.push_back(n_card);
        } else {
            Nursik.push_back(b_card);
            Nursik.push_back(n_card);
        }
    }

    if (Boris.empty()) {
        std::cout << "Nursik " << incr << std::endl;
    } else if (Nursik.empty()) {
        std::cout << "Boris " << incr << std::endl;
    } else {
        std::cout << "blin nichya" << std::endl;
    }

    return 0;
}
