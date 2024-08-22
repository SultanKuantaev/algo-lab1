#include <bits/stdc++.h>

int main() {
    std::string s;
    
    // Read input until "!" is encountered.
    while (true) {
        std::string c;
        std::cin >> c;
        s += c;
        if (c == "!") {
            break;
        }
    }
    
    std::deque<int> dq;
    
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '+') {
            if (i + 1 < s.length() && std::isdigit(s[i + 1])) {
                dq.push_front(s[i + 1] - '0');
                i++; // Skip the next character since it's part of the operation.
            } else {
                std::cout << "Error: No digit found after '+'\n";
            }
        } else if (s[i] == '-') {
            if (i + 1 < s.length() && std::isdigit(s[i + 1])) {
                dq.push_back(s[i + 1] - '0');
                i++; // Skip the next character since it's part of the operation.
            } else {
                std::cout << "Error: No digit found after '-'\n";
            }
        } else if (s[i] == '*') {
            if (dq.size() > 1) {
        std::cout << dq.front() + dq.back() << std::endl;
        dq.pop_front();
        dq.pop_back();
        } else if (dq.size() == 1) {
            std::cout << dq.front() + dq.front() << std::endl; // or dq.back() + dq.back()
        dq.pop_front(); // Just pop the one element
        } else {
            std::cout << "error\n";
}

        } else if (std::isdigit(s[i])) {
            // Handling unexpected digits directly in the string (just ignore them)
            continue;
        } else if (s[i] == '!') {
            break; // Stop processing if "!" is encountered.
        } else {
            std::cout << "Error: Unexpected character '" << s[i] << "'\n";
        }
    }
    
    return 0;
}
