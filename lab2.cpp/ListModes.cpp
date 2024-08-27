#include <bits/stdc++.h>

int main() {
    int n;
    std::cin >> n;
    std::map<int, int> freq;

    for (int i = 0; i < n; i++) {
        int num;
        std::cin >> num;
        freq[num]++;
    }

    int max_frequency = 0;
    for (const auto& pair : freq) {
        if (pair.second > max_frequency) {
            max_frequency = pair.second;
        }
    }

    for (auto it = freq.rbegin(); it != freq.rend(); ++it) {
        if (it->second == max_frequency) {
            std::cout << it->first << " ";
        }
    }
}
