#include <bits/stdc++.h>

struct Node {
    int value;  // значение, которое хранит узел
    Node* next; // указатель на следующий узел

    // Конструктор для создания нового узла
    Node(int val) : value(val), next(nullptr) {}
};

class LinkedList {
public:
    Node* head; // указатель на первый элемент

    // Конструктор для инициализации пустого списка
    LinkedList() : head(nullptr) {}

    // Метод для добавления нового узла в конец списка
    void append(int value) {
        Node* new_node = new Node(value);  // Создаем новый узел с переданным значением
        // Если список пуст (head == nullptr), новый узел становится головным элементом
        if (!head) {
            head = new_node;
            return;
        }
        Node* temp = head;
        while (temp->next) {  // Проходим до последнего узла
            temp = temp->next;
        }
        temp->next = new_node;  // Присоединяем новый узел к последнему узлу списка
    }

    // Метод для удаления каждого второго узла в списке
    void delete2() {
        Node* current = head;
        while (current && current->next) {
            Node* temp = current->next;  // Указатель на узел, который нужно удалить
            current->next = current->next->next;  // Пропускаем узел, связывая текущий с последующим
            delete temp;  // Удаляем ненужный узел из памяти
            current = current->next;  // Переходим через один узел
        }
    }

    // Метод для вывода элементов списка на экран
    void print_list() {
        Node* temp = head;
        while (temp) {  // Проходим по всему списку
            std::cout << temp->value << " ";  // Выводим значение текущего узла
            temp = temp->next;  // Переходим к следующему узлу
        }
        std::cout << std::endl;  // Печатаем новую строку после вывода всех элементов
    }
};  // Не забудьте закрыть фигурную скобку после определения класса

int main() {
    int n;
    std::cin >> n;  // Читаем количество элементов

    LinkedList list;  // Создаем объект связного списка

    for (int i = 0; i < n; i++) {
        int value;
        std::cin >> value;
        list.append(value);  // Добавляем элементы в список
    }

    list.delete2();  // Удаляем каждый второй элемент из списка
    list.print_list();  // Выводим оставшиеся элементы списка

    return 0;
}
