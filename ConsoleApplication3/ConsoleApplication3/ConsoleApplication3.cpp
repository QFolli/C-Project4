/*
1. Реализовать двусвязный список. За основу можно взять код из семинара для
односвязного списка.
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

class TDoublyLinkedList {
 private:
	Node* head = NULL;
	Node* tail = NULL;

 public:
	void push_front(int data)
	{
		Node* new_node = new Node(data);

		if (head!=NULL)
		{
			new_node->next = head;
			head->prev = new_node;
		}
		else
			tail = new_node;

		head = new_node;
	}

	void push_back(int data)
	{
		Node* new_node = new Node(data);

		if (tail!=NULL)
		{
			new_node->prev = tail;
			tail->next = new_node;
		}
		else
			head = new_node;

		tail = new_node;
	}

	void pop_front()
	{
		if (!head)
			exit(EXIT_FAILURE);

		Node* tmp = head;
		head = head->next;

		if (head)
			head->prev = nullptr;
		else
			tail = nullptr;

		delete tmp;
	}

	void pop_back()
	{
		if (!tail)
			exit(EXIT_FAILURE);

		Node* tmp = tail;
		tail = tail->prev;

		if (tail)
			tail->next = nullptr;

		else
			head = nullptr;

		delete tmp;
	}

	void print()
	{
		Node* current = head;

		while (current)
		{
			cout << current->data << "\t";
			current = current->next;
		}
		cout << endl;
	}
};


int main()
{
	setlocale(LC_ALL, "Russian");

	TDoublyLinkedList list;

	list.push_front(1);
	list.push_front(2);
	list.push_front(3);
	list.push_back(4);
	list.push_back(5);
	list.print(); // 3 2 1 4 5

	list.pop_front();
	list.pop_back();
	list.print(); // 2 1 4
}