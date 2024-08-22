#include <bits/stdc++.h>  // Подключение всех стандартных библиотек

// Определение структуры узла
struct Node {
    int data;  // Данные узла
    Node* next;  // Указатель на следующий узел

    // Конструктор для инициализации узла
    Node(int val) : data(val), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;  // Указатель на голову списка (первый элемент)
public:
    // Конструктор для создания пустого списка
    LinkedList() : head(nullptr) {}

    // Метод для вставки нового узла в конец списка
    void insert(int val) {
        Node* newNode = new Node(val);  // Создаем новый узел с данными val
        if (head == nullptr) {  // Если список пуст, новый узел становится головой
            head = newNode;
        } else {  // Иначе находим конец списка и добавляем узел туда
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    // Метод для поиска узла, значение которого ближе всего к k
    int findNearest(int k) {
        Node* temp = head;
        int min_distance = abs(temp->data - k);  // Начальное минимальное расстояние
        int min_index = 0;  // Индекс узла с минимальным расстоянием
        int current_index = 0;  // Текущий индекс в списке

        // Проходим по всему списку
        while (temp != nullptr) {
            int distance = abs(temp->data - k);  // Вычисляем расстояние до k
            if (distance < min_distance) {  // Если нашли меньшее расстояние
                min_distance = distance;
                min_index = current_index;  // Обновляем индекс
            }
            temp = temp->next;  // Переходим к следующему узлу
            current_index++;  // Увеличиваем текущий индекс
        }
        return min_index;  // Возвращаем индекс узла с минимальным расстоянием
    }
};

int main() {
    int n, k;
    std::cin >> n;  // Вводим количество элементов в списке

    LinkedList list;  // Создаем пустой связанный список
    for (int i = 0; i < n; i++) {
        int val;
        std::cin >> val;  // Вводим значение элемента
        list.insert(val);  // Вставляем его в список
    }

    std::cin >> k;  // Вводим значение k, к которому ищем ближайшее
    int nearestIndex = list.findNearest(k);  // Ищем индекс ближайшего значения
    std::cout << nearestIndex << std::endl;  // Выводим результат

    return 0;
}
