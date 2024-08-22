#include <iostream>
#include <deque>
#include <vector>

int main() {
    int n;
    std::cin >> n;
    std::deque<char> lead;
    std::vector<char> votes(n);
    
    for (int i = 0; i < n; i++) {
        std::cin >> votes[i];
        lead.push_back(votes[i]);
    }

    while (true) {
        int count_s = 0;
        int count_k = 0;
        
        for (char c : lead) {
            if (c == 'S') count_s++;
            else count_k++;
        }
        
        if (count_s == 0) {
            std::cout << "Katsu";
            break;
        }
        if (count_k == 0) {
            std::cout << "Satu";
            break;
        }
        
        char current = lead.front();
        lead.pop_front();
        
        if (current == 'S') {
            for (int i = 0; i < lead.size(); i++) {
                if (lead[i] == 'K') {
                    lead.erase(lead.begin() + i);
                    break;
                }
            }
            lead.push_back('S');
        } else {
            for (int i = 0; i < lead.size(); i++) {
                if (lead[i] == 'S') {
                    lead.erase(lead.begin() + i);
                    break;
                }
            }
            lead.push_back('K');
        }
    }

    return 0;
}
