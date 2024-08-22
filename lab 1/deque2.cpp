#include <bits/stdc++.h>

int main() {
    std::deque<int> dq;
    std::string command;

    while (std::cin >> command) {
        if (command[0] == '+') {
            if (command.length() > 1 && std::isdigit(command[1])) {
                dq.push_front(command[1] - '0');
            } else {
                std::cout << "Error: No digit found after '+'\n";
            }
        } else if (command[0] == '-') {
            if (command.length() > 1 && std::isdigit(command[1])) {
                dq.push_back(command[1] - '0');
            } else {
                std::cout << "Error: No digit found after '-'\n";
            }
        } else if (command[0] == '*') {
            if (!dq.empty()) {
                int front = dq.front();
                dq.pop_front();
                if (!dq.empty()) {
                    int back = dq.back();
                    dq.pop_back();
                    std::cout << front + back << std::endl;
                } else {
                    std::cout << front << std::endl;
                }
            } else {
                std::cout << "error\n";
            }
        } else if (command[0] == '!') {
            break; // Stop processing if "!" is encountered.
        } else {
            std::cout << "Error: Unexpected command '" << command << "'\n";
        }
    }

    return 0;
}
