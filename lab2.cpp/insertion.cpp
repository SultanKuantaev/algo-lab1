#include<bits/stdc++.h>

struct Node {
    int data;
    Node* next;
    Node(int data) : data(data), next(nullptr) {} // Corrected missing semicolon
};

Node* insertion(Node* head, int data, int position) {
    Node* newNode = new Node(data);

    if (position == 0) {
        newNode->next = head;
        return newNode;
    }

    Node* current = head;
    for (int i = 0; i < position - 1 && current != nullptr; i++) {
        current = current->next;
    }
    if (current != nullptr) {
        newNode->next = current->next;
        current->next = newNode;
    }
    return head;
}

void print(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
}

int main() {
    int n;
    std::cin >> n;

    Node* head = nullptr;
    Node* tail = nullptr;

    for (int i = 0; i < n; i++) {
        int value;
        std::cin >> value;
        Node* newNode = new Node(value); // Renamed to newNode for clarity
        if (head == nullptr) {
            head = newNode; // Changed to assign newNode
            tail = newNode; // Changed to assign newNode
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    int data, position;
    std::cin >> data >> position;

    head = insertion(head, data, position);

    print(head);
    return 0; // Added return statement
}
