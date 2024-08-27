#include <bits/stdc++.h>

using namespace std;

struct Node {
    Node* prev;
    Node* next;
    string val;
    Node(string _val) {
        prev = NULL;
        next = NULL;
        val = _val;
    }
};

Node* head = NULL;
Node* tail = NULL;
int cnt = 0;

void add_back(string s) {
    Node* newNode = new Node(s);
    if (tail == NULL) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
    cnt++;
}

void add_front(string s) {
    Node* newNode = new Node(s);
    if (head == NULL) {
        head = tail = newNode;
    } else {
        head->prev = newNode;
        newNode->next = head;
        head = newNode;
    }
    cnt++;
}

bool empty() {
    return cnt == 0;
}

void erase_front() {
    if (head == NULL) return; // Защита от удаления из пустого списка
    Node* temp = head;
    if (head == tail) {
        head = tail = NULL;
    } else {
        head = head->next;
        head->prev = NULL;
    }
    delete temp;
    cnt--;
}

void erase_back() {
    if (tail == NULL) return; // Защита от удаления из пустого списка
    Node* temp = tail;
    if (head == tail) {
        head = tail = NULL;
    } else {
        tail = tail->prev;
        tail->next = NULL;
    }
    delete temp;
    cnt--;
}

string front() {
    if (empty()) return "error";
    else {
        return head->val;
    }
}

string back() {
    if (empty()) return "error";
    else {
        return tail->val;
    }
}

void clear() {
    while (!empty()) {
        erase_front();
    }
}

int main() {
    string s;
    while (cin >> s) {
        if (s == "add_front") {
            string t;
            cin >> t;
            add_front(t);
            cout << "ok" << endl;
        }
        if (s == "add_back") {
            string t;
            cin >> t;
            add_back(t);
            cout << "ok" << endl;
        }
        if (s == "erase_front") {
            if (empty()) {
                cout << "error" << endl;
            } else {
                cout << front() << endl;
                erase_front();
            }
        }
        if (s == "erase_back") {
            if (empty()) {
                cout << "error" << endl;
            } else {
                cout << back() << endl;
                erase_back();
            }
        }
        if (s == "front") {
            if (empty()) {
                cout << "error" << endl;
            } else {
                cout << front() << endl;
            }
        }
        if (s == "back") {
            if (empty()) {
                cout << "error" << endl;
            } else {
                cout << back() << endl;
            }
        }
        if (s == "clear") {
            clear();
            cout << "ok" << endl;
        }
        if (s == "exit") {
            cout << "goodbye" << endl;
            break;
        }
    }
    return 0;
}
