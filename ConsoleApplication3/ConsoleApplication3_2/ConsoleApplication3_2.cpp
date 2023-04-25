/*
3. Реализовать очередь используя двусвязный список.
a. queue_push
b. queue_pop
c. queue_front //вернуть указатель (или значение) хранимое в начале
очереди
*/
#include <stdio.h>
#include <iostream>
#include <string>

#pragma warning(disable : 4996);

using namespace std;

struct Node {
    Node(int data) : data(data), prev(nullptr), next(nullptr) {
    }

    int data;
    Node* prev;
    Node* next;
};

class TQueue {
public:
    Node* head;
    Node* tail;

public:
    void queue_push(int data) {
        Node* newNode = new Node(data);

        if (tail == nullptr)
            head = tail = newNode;
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void queue_pop() {
        if (head == nullptr) {
            cout << "Очередь пуста" << endl;
            exit(EXIT_FAILURE);
        }

        Node* temp = head;
        head = head->next;

        if (head != nullptr)
            head->prev = nullptr;
        else
            tail = nullptr;

        delete temp;
    }

    int queue_front() {
        if (head == nullptr) {
            cout << "Очередь пуста" << endl;
            exit(EXIT_FAILURE);
        }

        return head->data;
    }
};

int main()
{
    setlocale(LC_ALL, "Russian");

    TQueue q;

    q.queue_push(1);
    q.queue_push(2);
    q.queue_push(3);

    cout << "Передний элемент: " << q.queue_front() << endl;

    q.queue_pop();
    cout << "Передний элемент после вызова queue_pop: " << q.queue_front() << endl;

    q.queue_pop();
    cout << "Передний элемент после вызова queue_pop: " << q.queue_front() << endl;

    q.queue_pop();
    cout << "Передний элемент после вызова queue_pop: " << q.queue_front() << endl;
}